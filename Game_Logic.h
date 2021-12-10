#ifndef GAME_LOGIC_H__
#define GAME_LOGIC_H_

#include "io_utils.h"
#include "Point.h"
#include "Board.h"
#include "Color.h"
#include <vector>
#include "Pacman.h"
#include "Ghost.h"
#include "Fruit.h"

class Game_Logic {

private:
	Board board;
	Pacman pacman;
	std::vector<Ghost> ghosts;
	Fruit fruit;
	bool black_and_white;
	char ghostLevel;

	public:
		//--------Constructors--------//
		Game_Logic();

		//-----Setters & Getters------//
		void setGameLogic(Point p);
		void setGhostLevel(char _ghostLevel) {ghostLevel = _ghostLevel;	}
		char getGhostLevel() { return ghostLevel; }

		//----------Methods-----------//

		char menu();
		char levelMenu();

		void getInput(bool& flag);
		void runGame();
		void run();
		
		void creaturesCollision(bool& flag, bool& fruitActive);
		void winGame();
		void gameOver();
		void resetGame(string s);

		void printMenu();
		void printInstractions();
		void printLevelMenu();
		void printGamePause();
		void printExit();

		Point getRandomPoint();

private:
		bool collision(const Creature& A, const Creature& B);
		void ghostPacmanCollision(bool& didILose);
		void fruitPacmanCollision(bool& fruitActive);
		void hideFruit(bool& fruitActive);
};

#endif