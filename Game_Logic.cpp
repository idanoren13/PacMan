#include "Game_Logic.h"

Game_Logic::Game_Logic() {
	std::srand(std::time(nullptr));
	black_and_white = true;
	ghost1.setGhost(Point(20, 9), board);
	ghost2.setGhost(Point(23, 9), board);
}

void Game_Logic::runGame() {
	char choice;
	ShowConsoleCursor(false); //hiding console cursor
	while (true)
	{
		choice = menu();
		switch (choice) {
		case '1':
			black_and_white = false;
			ghost1.setColor(RED);
			ghost2.setColor(MAGENTA);
			pacman.setColor(YELLOW);
			run();
			break;
		case '2':
			black_and_white = true;
			ghost1.setColor(WHITE);
			ghost2.setColor(WHITE);
			pacman.setColor(WHITE);
			run();
			break;
		case '9':
			printExit();
			return;
		}
	}
}

void Game_Logic::run()
{
	int slowTheGhost = 1;
	Move_Vector dir = STAY;

	bool pauseFlag = false;
	bool didILose = false;

	board.printBoard(black_and_white);
	pacman.printCreature();
	ghost1.printCreature();
	ghost2.printCreature();

	while (pacman.getScore() < MAX_SCORE && !didILose) {
		getInput(pauseFlag);
		if (!pauseFlag) {
			pacman.movePacman(board);
			if (slowTheGhost % 2 == 0) {
				ghost1.moveGhost(board);
				ghost2.moveGhost(board);
			}
			slowTheGhost++;
		}
		else
			printGamePause();			

		isGameOver(didILose);
		if (!didILose) {
			board.printData(pacman.getScore(), pacman.getLife());
			Sleep(100);
		}
	}
	if(!didILose)
		winGame();
	didILose = false;
}

void Game_Logic::isGameOver(bool& flag) {
	if (collision()) {
		pacman.setLife(pacman.getLife()-1);
		if (pacman.getLife() <= 0) {
			gameOver();
			flag = !flag;
		}
		else {
			pacman.setPacman(Point(2, 9));
			ghost1.setGhost(Point(21, 9), board);
			ghost2.setGhost(Point(22, 9), board);
		}
	}
}

bool Game_Logic::collision() {
	return (pacman.getCurrPoint().isSamePoint(ghost1.getCurrPoint()) ||
		pacman.getCurrPoint().isSamePoint(ghost2.getCurrPoint()) ||
		pacman.getPrevPoint().isSamePoint(ghost1.getPrevPoint()) ||
		pacman.getPrevPoint().isSamePoint(ghost2.getPrevPoint()));
}

void Game_Logic::gameOver()
{
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
	string s = "   _____      ___       ___  ___   _______ \n  /  ___|    /   |     /   |/   | |   ____| \n  | |       /    |    / /|   /| | |  |__ \n  | |  _   /  /| |   / / |__/ | | |   __| \n  | |_| | /  ___ |  / /       | | |  |____ \n  \\_____//_/   |_| /_/        |_| |_______| \n\n   _____    _     _   ______   ______ \n  /  _  \\  | |   / / | _____| |  _   \\ \n  | | | |  | |  / /  | |__    | |_|  | \n  | | | |  | | / /   |  __|   |  _   / \n  | |_| |  | |/ /    | |____  | | \\  \\ \n  \\_____/  |___/     |______| |_|  \\__\\  \n\nPress any key to return to the menu\n";

	resetGame(s);
}

void Game_Logic::winGame(){
	/*prints:
		__     ______  _    _  __          _______ _   _
		\ \   / / __ \| |  | | \ \        / /_   _| \ | |
		 \ \_/ / |  | | |  | |  \ \  /\  / /  | | |  \| |
		  \   /| |  | | |  | |   \ \/  \/ /   | | | . ` |
		   | | | |__| | |__| |    \  /\  /   _| |_| |\  |
		   |_|  \____/ \____/      \/  \/   |_____|_| \_|*/
	string s = " __     ______  _    _  __          _______ _   _\n \\ \\   / / __ \\| |  | | \\ \\        / /_   _| \\ | |\n  \\ \\_/ / |  | | |  | |  \\ \\  /\\  / /  | | |  \\| |\n   \\   /| |  | | |  | |   \\ \\/  \\/ /   | | | . ` |\n    | | | |__| | |__| |    \\  /\\  /   _| |_| |\\  |\n    |_|  \\____/ \\____/      \\/  \\/   |_____|_| \\_|\n\nPress any key to return to the menu\n";

	resetGame(s);
}

void Game_Logic::resetGame(string s){
	char ch;
	clear_screen();
	gotoxy(0, 0);
	setTextColor(Color(WHITE));
	cout << s;

	_getch();
	system("cls");

	board.initBoard();
	pacman.setPacman(Point(2, 9));
	pacman.setLife(3);
	ghost1.setGhost(Point(21, 9), board);
	ghost2.setGhost(Point(22, 9), board);
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

char Game_Logic::menu()
{
	printMenu();
	char choice = _getch();

	while (choice != '1' && choice != '2' && choice != '9'){
		if (choice == '8') {
			printInstractions();
			printMenu();
		}
		else {
			gotoxy(0, 16);
			cout << "Invalid choice. Choose a number from [1/2/8/9]:" << endl;
		}
		choice = _getch();
	}
	system("cls");
	return choice;
}

void Game_Logic::printMenu() {
	gotoxy(0, 0);
	cout << "" << endl
		<< "********************************************" << endl
		<< "    _____           __  __			      " << endl
		<< "   |  __ \\	   |  \\/  |		      " << endl
		<< "   | |__) |_ _  ___| \\  / | __ _ _ __      " << endl
		<< "   | ___ / _` |/ __| |\\/| |/ _` | '_ \\    " << endl
		<< "   | |  | (_| | (__| |  | | (_| | | | |     " << endl
		<< "   |_|   \\__,_|\\___|_|  |_|\\__,_|_| |_|   " << endl
		<< "                                            " << endl
		<< "********************************************" << endl
		<< "Choose option from the following menu: " << endl
		<< " 1.\tStart a new game (with colors) " << endl
		<< " 2.\tStart a new game (without colors) " << endl
		<< " 8.\tInstructions and keys " << endl
		<< " 9.\tExit." << endl;
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

void Game_Logic::printGamePause() {
	setTextColor(Color::WHITE);
	gotoxy(0, HEIGHT + 3);
	cout << "Game paused, press ESC again to continue";
	Sleep(950);
	cout << "\33[2K" << endl; // erase line from console
	Sleep(200);
}