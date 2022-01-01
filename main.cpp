#include "Regular_Mode.h"
#include "Load_Mode.h"

void main(char** argv, int argc) {
	if (argc == 0){
		Regular_Mode game;
		game.runGame();
	}
	else { // TODO: handle silent mode
		Load_Mode game;
		game.runGame();
	}
	// Game_Logic game;
	// game.runGame();
}

