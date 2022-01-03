#include "Load_Mode.h"

Load_Mode::Load_Mode() {
	silent = false;
	printer.setSilentMode(silent);
	fruitActive = false;
}

Load_Mode::Load_Mode(bool _silent) {
	silent = _silent;
	printer.setSilentMode(silent);
	fruitActive = false;
}


void Load_Mode::runGame(bool s) {
	silent = s;
	run();
	/*if (silent)
		runSilentMode();
	else
		run();*/
}

void Load_Mode::run() {
	bool didILose = false;
	initScreens();

	for (string& screen : screenNames)
	{
		resetGame(screen);
		if (!board.isValidScreen())
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
		printer.printMsg("You won the last screen, congrats !\n");
}

void Load_Mode::runScreen(bool& didILose) {
	int slowCreature = 0;

	if (!silent) {
		board.printBoard(black_and_white);
		pacman.printCreature();
	}

	while (pacman.getScore() < board.getNumOfCrumbs() && !didILose) {
		//getInput(pauseFlag, continue_game);
		decodeLine(my_stream.readFromQueue());
		pacman.move(board);
		if (slowCreature % 2 == 0) {
			for (Ghost& ghost : ghosts) {
				ghost.move(board);
			}
		}
		if (fruitActive) {
			if (slowCreature % 6 == 0)
				fruit.controledMove(board);
			if (slowCreature % 203 == 0)
				fruitActive = false;
		}
		//else {
		//	fruit.hideFruit(board);
		//}
		slowCreature++;
		creaturesCollision(didILose, fruitActive);

		board.printData(pacman.getScore() + pacman.getFruitScore(), pacman.getLife());

		if (!silent)
			Sleep(100);
	}
}

void Load_Mode::resetGame(string screen) {
	Game_Logic::resetGame(screen);
	my_stream.makeEmptyQueue();
	my_stream.readFromFile(screen);
	for (int i = 0; i < board.getNumOfGhosts(); i++) {
		ghosts[i].setGhostLevel('d'); //controled
	}
}
// num of ghosts
// pgggg\n
// pggg 99 99 f\n
// p[0-4]g[\n | 99 99 f\n]

void Load_Mode::decodeLine(string line) {
	// read until ' ' check next or \n

	std::stringstream ss;
	std::string temp;
	int coordX,coordY;
	char v,val;
	int i;
	ss << line;
	ss >> coordX;
	ss >> coordY;

	pacman.setNextPoint(Point(coordX, coordY));
	
	for (Ghost& ghost : ghosts) {
		//ghost.setVector(char2Vector(line[i]));
		i++;
	}
	if (line[i] == ' ') { // fruit is activated
		fruitActive = true;
		ss << line.substr(i, line.size() - 1);
		ss >> coordX;
		ss >> coordY;
		ss >> v;
		ss >> val;
		fruit.setVector(char2Vector(v));
		fruit.setShape((Shape)(val));
		fruit.setCurrPoint(Point(coordX, coordY));


		// update fruit shape
	}
	else
		fruitActive = false;
}

void Load_Mode::runSilentMode() {

}


Move_Vector Load_Mode::char2Vector(char ch) {
	Move_Vector v;
	switch (ch)
	{
	case 'u':
		v = UP;
		break;
	case 'd':
		v = DOWN;
		break;
	case 'l':
		v = LEFT;
		break;
	case 'r':
		v = RIGHT;
		break;
	case 's':
		v = STAY;
		break;
	default:
		v = STAY;
		//throw exception invalid character in file (prints the character)
		break;
	}
	return v;
}
