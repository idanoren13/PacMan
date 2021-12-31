#include "Regular_Game.h"
#include "Load_Game.h"

void main(char** argv, int argc) {
	if (argc == 0){
		Regular_Game game;
		game.runGame();
	}
	else { // TODO: handle silent mode
		Load_Game game;
		game.runGame();
	}
	// Game_Logic game;
	// game.runGame();
}

