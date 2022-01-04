#include "Game_Logic.h"

Game_Logic::Game_Logic() {
	std::srand(std::time(nullptr));
	ShowConsoleCursor(false); // hiding console cursor
	black_and_white = false;
}

void Game_Logic::resetGame(string screen) {
	//reset board
	board.initBoard(screen.c_str());
	if (!board.isValidScreen()) {
		printer.printMsg(board.getErrMsg());
		return;
	}
	
	//reset pacman
	pacman.resetScore();
	pacman.setPacman(board.getPacmanPos());
	pacman.setVector(Move_Vector(STAY));

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

void Game_Logic::readScreens() {
	if (fileName.size()) {
		if (fileName.find(".screen") != string::npos)
			screenNames.push_back(static_cast<string>(fileName));
		else {
			printer.printMsg("File should end with .screen");
			return;
		}
	}
	else
		initScreens();
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
		if (collision(pacman, ghost)) {
			ghostPacmanCollision(didILose);
			break;
		}

		if (collision(fruit, ghost))
			hideFruit(fruitActive);
	}
	
	if (collision(pacman, fruit) && fruitActive)	
		fruitPacmanCollision(fruitActive);
}

void Game_Logic::ghostPacmanCollision(bool& didILose) {
	pacman.setLife(pacman.getLife() - 1);
	if (pacman.getLife() <= 0) 
		didILose = true;
	else
	{
		for (int i = 0; i < ghosts.size(); i++)
			ghosts[i].setGhost((board.getGhostsPos())[i], board);
		pacman.setPacman(board.getPacmanPos());
	}
}

void Game_Logic::fruitPacmanCollision(bool& fruitActive) {
	pacman.setFruitScore((int)(fruit.getShape() - '0'));
	hideFruit(fruitActive);
	Print_Creature::get().printObj(pacman.getCurrPoint(), pacman.getShape());
	//pacman.printCreature();
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

void Game_Logic::getInput(bool& flag, bool& continue_game) {
	int s;
	Move_Vector dir;
	if (_kbhit()) {
		s = _getch();
		if (s == 27) // Pause game if user presses ESC  
			flag = !flag;
		else if (flag && (s =='H' || s == 'h')) {
			continue_game = !continue_game;
		}
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
	printer.printMsg(s);
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
	printer.printMsg(s);
}


