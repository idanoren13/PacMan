#include "Game_Logic.h"

Game_Logic::Game_Logic() {
	std::srand(std::time(nullptr));
	ShowConsoleCursor(false); // hiding console cursor
	black_and_white = true;
	ghostLevel = 'c';
}

void Game_Logic::runGame() {
	char choice;

	while (true)
	{
		choice = menu();
		
		switch (choice) {
		case '1':
			black_and_white = false;
			run();
			break;
		case '2':
			black_and_white = true;
			run();
			break;
		case '9':
			printExit();
			return;
		}
		fileName = "";
		screenNames.clear();
	}
}

void Game_Logic::run() {
	bool didILose = false;
	bool isValidFile = true;

	if (fileName.size()/**/) {
		if (fileName.find(".screen") != string::npos)
			screenNames.push_back(static_cast<string>(fileName));
		/*else
			printMsg();*/
	}
	else
		initScreens();

	for (string& screen : screenNames) {
		resetGame(screen, isValidFile);
		if (!isValidFile)
			return;
		runScreen(didILose);
		if (!didILose)
			winGame();
		else {
			gameOver();
			break;
		}
	}
	if (!didILose)
		printMsg("You won the last screen, congrats !\n");
}

void Game_Logic::runScreen(bool& didILose)
{
	int slowCreature = 1;
	bool pauseFlag = false;
	bool fruitActive = false;

	board.printBoard(black_and_white);
	pacman.printCreature();

	while (pacman.getScore() < board.getNumOfCrumbs() && !didILose) {
		getInput(pauseFlag);
		if (!pauseFlag) {
			pacman.move(board);
			if (slowCreature % 2 == 0) {
				for (Ghost& ghost : ghosts)
					ghost.move(board);
			}
			if (fruitActive) {
				if (slowCreature % 6 == 0)
					fruit.move(board);
				if (slowCreature % 200 == 0)
					hideFruit(fruitActive);
			}
			if (!fruitActive && (pacman.getScore() > 40) && (rand() % 59 == 0)) {
				fruitActive = true;
			}
			slowCreature++;
			creaturesCollision(didILose, fruitActive);
			board.printData(pacman.getScore() + pacman.getFruitScore(), pacman.getLife());
		}
		else
			printGamePause();

		Sleep(100);
	}
}

void Game_Logic::resetGame(string screen, bool& isValidFile) {
	//reset board
	string errMsg;
	board.initBoard(screen.c_str(), isValidFile, errMsg);
	if (!isValidFile) {
		printMsg(errMsg);
		return;
	}
	
	//reset pacman
	pacman.resetScore();
	pacman.setPacman(board.getPacmanPos());

	//reset ghost
	ghosts.clear();
	for (int i = 0; i < board.getNumOfGhosts(); i++)
		ghosts.push_back(Ghost((board.getGhostsPos())[i]));

	if (black_and_white) {
		for (auto&& ghost : ghosts)
			ghost.setColor(WHITE);
		pacman.setColor(WHITE);
	}
	else {
		int j = 2;
		for (auto&& ghost : ghosts) {
			ghost.setColor(Color(j));
			j++;
		}
		pacman.setColor(YELLOW);
	}
}

void Game_Logic::initScreens() {
	const fs::path projPath = fs::current_path();

	for (const auto& entry : fs::directory_iterator(projPath)) {
		auto fileName = entry.path().filename().string();
		if (entry.is_regular_file())
			if (fileName.find(".screen") != string::npos)
				screenNames.push_back(static_cast<string>(fileName));
	}
	sort(screenNames.begin(), screenNames.end());
}

void Game_Logic::creaturesCollision(bool& didILose, bool& fruitActive) {

	for (Ghost& ghost : ghosts) {
		if (collision(pacman, ghost))
			ghostPacmanCollision(didILose);

		if (collision(fruit, ghost))
			hideFruit(fruitActive);
	}
	
	if (collision(pacman, fruit))	
		fruitPacmanCollision(fruitActive);
}

void Game_Logic::ghostPacmanCollision(bool& didILose) {
	pacman.setLife(pacman.getLife() - 1);
	if (pacman.getLife() <= 0) 
		didILose = true;
	else {
		pacman.setPacman(board.getPacmanPos());
		for (int i = 0; i < ghosts.size(); i++)
			ghosts[i].setGhost((board.getGhostsPos())[i], board);
	}
}

void Game_Logic::fruitPacmanCollision(bool& fruitActive) {
	pacman.setFruitScore((int)(fruit.getShape() - '0'));
	//pacman.printCreature();
	hideFruit(fruitActive);
}

void Game_Logic::hideFruit(bool& fruitActive) {
	fruit.setFruit(board.getRandomPoint(), board);
	fruit.setShape(Shape(FIVE + rand() % 5));
	fruitActive = false;
}

bool Game_Logic::collision(const Creature& A, const Creature& B) {
	return (A.getCurrPoint().isSamePoint(B.getCurrPoint()) ||
		A.getPrevPoint().isSamePoint(B.getPrevPoint()));
}

void Game_Logic::getInput(bool& flag) {
	int s;
	Move_Vector dir;
	if (_kbhit()) {
		s = _getch();
		if (s == 27) // Pause game if user presses ESC  
			flag = !flag;
		else {
			if (s == 'w' || s == 'W')
				dir = UP;
			else if (s == 'a' || s == 'A')
				dir = LEFT;
			else if (s == 'd' || s == 'D')
				dir = RIGHT;
			else if (s == 's' || s == 'S')
				dir = DOWN;
			else if (s == ' ' || s == ' ')
				dir = STAY;
			else
				return;
			pacman.setVector(dir);
		}
	}
}

char Game_Logic::menu() {
	printMenu();
	char choice = _getch();
	char levelChoice;

	while (choice != '1' && choice != '2' && choice != '9') {
		switch (choice) {
		case '3':
			levelChoice = levelMenu();
			setGhostLevel(levelChoice);
			printMenu();
			break;
		case '4':
			chooseBoard();
			printMenu();
			break;
		case '8':
			printInstractions();
			printMenu();
			break;
		default:
			gotoxy(0, 19);
			cout << "Invalid choice. Choose a number from [1/2/3/4/8/9]" << endl;
			gotoxy(0, 0);
			break;
		}
		choice = _getch();
	}
	system("cls");
	return choice;
}

char Game_Logic::levelMenu()
{
	printLevelMenu();
	char choice = _getch();

	while (choice != 'a' && choice != 'b' && choice != 'c') {
		gotoxy(0, 16);
		cout << "Invalid choice. Choose a letter from [a/b/c]" << endl;
		choice = _getch();
	}
	system("cls");
	return choice;
}

void Game_Logic::chooseBoard() {  // split to 2 funcs
	system("cls");
	gotoxy(0, 0);

	printPacmanSign();
	cout << "Please insert screen name : " << endl;
	fileName.clear();
	cin >> fileName;

	//while (choice[0] < '0' || choice[0] > '9' || choice[1] < '0' || choice[1] > '9') {
	//	gotoxy(0, 16);
	//	cout << "Invalid choice.\nScreen does not exist." << endl;
	//	gotoxy(0, 11); 
	//	cout << "\33[2K";
	//	cin >> choice;
	//}
	//setFileName(choice);
	//resetGame("Loading Screen");
	system("cls");
}

void Game_Logic::gameOver()
{
	pacman.setLife(3);
	/*prints:
	*    _____      ___       ___  ___   _______
		/  ___|    /   |     /   |/   | |   ____|
		| |       /    |    / /|   /| | |  |__
		| |  _   /  /| |   / / |__/ | | |   __|
		| |_| | /  ___ |  / /       | | |  |____
		\_____//_/   |_| /_/        |_| |_______|

		 _____    _     _   ______   ______
		/  _  \  | |   / / | _____| |  _   \
		| | | |  | |  / /  | |__    | |_|  |
		| | | |  | | / /   |  __|   |  _   /
		| |_| |  | |/ /    | |____  | | \  \
		\_____/  |___/     |______| |_|  \__\ */
	string s = "   _____      ___       ___  ___   _______ \n  /  ___|    /   |     /   |/   | |   ____| \n  | |       /    |    / /|   /| | |  |__ \n  | |  _   /  /| |   / / |__/ | | |   __| \n  | |_| | /  ___ |  / /       | | |  |____ \n  \\_____//_/   |_| /_/        |_| |_______| \n\n   _____    _     _   ______   ______ \n  /  _  \\  | |   / / | _____| |  _   \\ \n  | | | |  | |  / /  | |__    | |_|  | \n  | | | |  | | / /   |  __|   |  _   / \n  | |_| |  | |/ /    | |____  | | \\  \\ \n  \\_____/  |___/     |______| |_|  \\__\\  \n\nReturning to the menu";
	printMsg(s);
}

void Game_Logic::winGame() {
	/*prints:
		__     ______  _    _  __          _______ _   _
		\ \   / / __ \| |  | | \ \        / /_   _| \ | |
		 \ \_/ / |  | | |  | |  \ \  /\  / /  | | |  \| |
		  \   /| |  | | |  | |   \ \/  \/ /   | | | . ` |
		   | | | |__| | |__| |    \  /\  /   _| |_| |\  |
		   |_|  \____/ \____/      \/  \/   |_____|_| \_|*/
	string s = " __     ______  _    _  __          _______ _   _\n \\ \\   / / __ \\| |  | | \\ \\        / /_   _| \\ | |\n  \\ \\_/ / |  | | |  | |  \\ \\  /\\  / /  | | |  \\| |\n   \\   /| |  | | |  | |   \\ \\/  \\/ /   | | | . ` |\n    | | | |__| | |__| |    \\  /\\  /   _| |_| |\\  |\n    |_|  \\____/ \\____/      \\/  \\/   |_____|_| \\_|\n\nLoading next screen";
	printMsg(s);
}

void Game_Logic::printMsg(string s) {
	clear_screen();
	gotoxy(0, 0);
	setTextColor(Color(WHITE));
	s.append("\nPlease wait\n");
	cout << s;
	Sleep(3300);
	system("cls");
}

void Game_Logic::printGamePause() {
	setTextColor(Color::WHITE);
	gotoxy(0, board.getHeight() + 3);
	cout << "Game paused, press ESC again to continue";
	Sleep(950);
	cout << "\33[2K" << endl; // erase line from console
	Sleep(200);
}

void Game_Logic::printMenu() {
	gotoxy(0, 0);
	setTextColor(Color::WHITE);
	printPacmanSign();
	cout << "Choose option from the following menu: " << endl
		<< " 1.\tStart a new game (with colors) " << endl
		<< " 2.\tStart a new game (without colors) " << endl
		<< " 3.\tChoose level " << endl
		<< " 4.\tInsert a screen name " << endl
		<< " 8.\tInstructions & keys " << endl
		<< " 9.\tExit" << endl;
}

void Game_Logic::printLevelMenu() {
	system("cls");
	gotoxy(0, 0);
	printPacmanSign();
	cout << "Choose game level [a/b/c] " << endl
		<< " a.\tBEST " << endl
		<< " b.\tGOOD " << endl
		<< " c.\tNOVICE " << endl;
}

void Game_Logic::printInstractions() {
	system("cls");
	cout << "\nWelcome to Pacman !" << endl << "Your goal is to move the pacman on the screen and eat the breadcrumbs." << endl
		<< "Each eaten breadcrumb equals a point to be earned." << endl
		<< "Once all breadcrumbs on screen are eaten you win the game :)\n" << endl
		<< "Keys for the game (make sure to use english keyboard!) :" << endl
		<< "LEFT -> a or A" << endl
		<< "RIGHT -> d or D" << endl
		<< "UP -> w or W" << endl
		<< "DOWN -> x or X" << endl
		<< "STAY -> s or S" << endl
		<< "ESC -> Pause" << endl << endl
		<< "Press any key to return to the menu" << endl;
	_getch();
	system("cls");
}

void Game_Logic::printPacmanSign() {
	cout << "" << endl
		<< "********************************************" << endl
		<< "    _____           __  __			      " << endl
		<< "   |  __ \\	   |  \\/  |		      " << endl
		<< "   | |__) |_ _  ___| \\  / | __ _ _ __      " << endl
		<< "   | ___ / _` |/ __| |\\/| |/ _` | '_ \\    " << endl
		<< "   | |  | (_| | (__| |  | | (_| | | | |     " << endl
		<< "   |_|   \\__,_|\\___|_|  |_|\\__,_|_| |_|   " << endl
		<< "                                            " << endl
		<< "********************************************" << endl;
}

void Game_Logic::printExit() {
	cout << endl
		<< "    .______                _____		   " << endl
		<< "   /       \\              /     \\		   " << endl
		<< "  /    O   /   _   _     / O O   \\     _   _   " << endl
		<< " |       ./   (_) (_)   |         |   (_) (_) " << endl
		<< " |       \\              | ~~~     | 	   " << endl
		<< " |        \\             |         |	   " << endl
		<< "  \\        /            |         |	   " << endl
		<< "   \\______/             |/vvvvvvv\\|      " << endl
		<< "\n             GOOD BYE     \n";
}

