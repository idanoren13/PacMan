#include "Regular_Mode.h"
#include "Load_Mode.h"

void test() {
	Regular_Mode game(true);
	Load_Mode _game(false);
	char x;
	std::cout << "press 1 for save mode, press 2 for load mode:" << std::endl;
	x = std::getchar();
	switch (x)
	{
	case '1':
		game.runGame();
		break;
	case '2':
		_game.runGame();
		break;
	default:
		break;
	}
}
void main(int argc, char** argv) {

	// ignore the ifs

	test();
//	if (argc == 0){
//	}
//	else { 
//		bool silent = false;
//		// if we get silent from argv, change to true
//		Load_Mode game;
//		game.runGame(silent);
//	}
//	// Game_Logic game;
//	// game.runGame();
}
