#include "Regular_Mode.h"
#include "Load_Mode.h"

void main(char** argv, int argc) {

	// ignore the ifs

	if (argc == 0){
		bool save_mode = false;
		Regular_Mode game;
		game.runGame(save_mode);
	}
	else { 
		bool silent = false;
		// if we get silent from argv, change to true
		Load_Mode game;
		game.runGame(silent);
	}
	// Game_Logic game;
	// game.runGame();
}

