#include "Load_Mode.h"

Load_Mode::Load_Mode(bool _silent) {
	silent = _silent; // need to be remove
	text_printer.setSilent(silent);
	creature_printer.setSilent(silent);
	fruitActive = false;
}


void Load_Mode::runGame() {
	
	bool didILose = false;
	initScreens();

	for (string& screen : screenNames)
	{
		resetGame(screen);
		if (!board.isValidScreen())
			return;

		runScreen(didILose);
		if(silent)
			compareResults(screen);
		if (!didILose)
			winGame();
		else {
			gameOver();
			break;
		}
	}
	if (!didILose)
		text_printer.printMsg("You won the last screen, congrats !\n");
}


void Load_Mode::runScreen(bool& didILose) {
	
	if (!silent) {
		board.printBoard(black_and_white);
		pacman.printCreature();
	}

	while (pacman.getScore() < board.getNumOfCrumbs() && !didILose) {
		decodeLine(my_stream.readFromQueue());
		pacman.controledMove(board);
		if (point_of_time % 2 == 0) {
			for (Ghost& ghost : ghosts) {
				ghost.move(board);
			}
		}
		if (fruitActive) {
			if (point_of_time % 6 == 0)
				fruit.controledMove(board);
			if (point_of_time % 203 == 0)
				fruitActive = false;
		}
		
		point_of_time++;
		creaturesCollision(didILose, fruitActive);

		text_printer.printData(pacman.getScore() + pacman.getFruitScore(), pacman.getLife(), board.getLegendPos());

		if (!silent)
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

//decodes the string (the commands) from q
void Load_Mode::decodeLine(string line) {
	std::stringstream ss;
	std::string temp;
	int coordX, coordY;
	char val;
	int i = 0;
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
	setTextColor(Color::WHITE);
	int* a = new int[2];
	my_stream.getResult(a, fileName);
	if (a[0] == point_of_time && a[1] == (pacman.getScore()+pacman.getFruitScore()))
		std::cout << "test succeed";
	else
		std::cout << "test failed";
	Sleep(2000);
	delete a;
}