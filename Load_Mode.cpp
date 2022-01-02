#include "Load_Mode.h"

Load_Mode::Load_Mode(bool _silent) {
	silent = _silent;
	printer.setSilentMode(silent);
	fruitActive = false;
}


void Load_Mode::runGame() {
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
				fruit.move(board);
			if (slowCreature % 203 == 0)
				fruitActive = false;
		}
		slowCreature++;
		creaturesCollision(didILose, fruitActive);
		board.printData(pacman.getScore() + pacman.getFruitScore(), pacman.getLife());

		if (!silent)
			Sleep(50);
	}
}

void Load_Mode::resetGame(string screen) {
	Game_Logic::resetGame(screen);
	my_stream.makeEmptyQueue();
	my_stream.readFromFile(screen);
}
// num of ghosts
// pgggg\n
// pggg 99 99 f\n
// p[0-4]g[\n | 99 99 f\n]

void Load_Mode::decodeLine(string line) {
	// read until ' ' check next or \n
	int i = 1;
	pacman.setVector((Move_Vector)line[0]);
	for (Ghost& ghost : ghosts) {
		ghost.setVector((Move_Vector)line[i]);
		i++;
	}
	if (line[i] == ' ') { // fruit is activated
		fruitActive = true;
		std::stringstream ss;
		ss << std::substr(i + 1, line.size() - 1);
		std::string temp;
		ss >> temp;


		// update fruit shape
	}
	else
		fruitActive = false;
}

void Load_Mode::runSilentMode() {

}
