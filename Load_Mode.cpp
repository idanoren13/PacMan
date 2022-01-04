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
	boris.setSilent(s);
	
	bool didILose = false;
	initScreens();

	for (string& screen : screenNames)
	{
		resetGame(screen);
		if (!board.isValidScreen())
			return;

		runScreen(didILose);
		//compareResults(screen);
		if (!didILose)
			winGame();
		else {
			gameOver();
			break;
		}
	}
	if (!didILose)
		printer.printMsg("You won the last screen, congrats !\n");
	if(silent){
		cout << "works";
	}
}


void Load_Mode::runScreen(bool& didILose) {
	
	slowCreature = 0;

	if (!silent) {
		board.printBoard(black_and_white);
		pacman.printCreature();
	}

	while (pacman.getScore() < board.getNumOfCrumbs() && !didILose) {
		decodeLine(my_stream.readFromQueue());
		pacman.controledMove(board);
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
		
		slowCreature++;
		creaturesCollision(didILose, fruitActive);

		board.printData(pacman.getScore() + pacman.getFruitScore(), pacman.getLife());

		//if (!silent)
			Sleep(20);
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
//decodes the string (the commands) from q
void Load_Mode::decodeLine(string line) {
	std::stringstream ss;
	std::string temp;
	int coordX, coordY;
	char v, val;
	int i;
	ss << line;
	ss >> coordX;
	ss >> coordY;

	pacman.setNextPoint(Point(coordX, coordY));

	for (Ghost& ghost : ghosts) {
		ss >> coordX;
		ss >> coordY;
		ghost.setNextPoint(Point(coordX, coordY));
	}
	if (ss >> coordX && ss >> coordY) { // fruit is activated
		fruitActive = true;
		ss >> val;
		fruit.setNextPoint(Point(coordX, coordY));
		fruit.setShape((Shape)(val));
	}
	else
		fruitActive = false;
}

void Load_Mode::compareResults(std::string fileName) {
	clear_screen();
	int* a = new int(2);
	my_stream.getResult(a, fileName);
	if (a[0] == slowCreature && a[1] == pacman.getScore())
		std::cout << "test succeed";
	else
		std::cout << "test failed";
	Sleep(2000);
	delete[] a;
}