#ifndef GAME_LOGIC_H__
#define GAME_LOGIC_H_
#define _CRT_SECURE_NO_WORNINGS

#include "io_utils.h"
#include "Point.h"
#include "Board.h"
#include "Color.h"
#include "Pacman.h"
#include "Ghost.h"
#include "Fruit.h"
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

class Game_Logic {

private:
	
	char ghostLevel;
	bool black_and_white;
	string fileName = "";

	Board board;
	Pacman pacman;
	Fruit fruit;
	std::vector<Ghost> ghosts;
	std::vector<string> screenNames;

public:
		//--------Constructors--------//
		Game_Logic();

		//-----Setters & Getters------//
		void setGhostLevel(char _ghostLevel) {ghostLevel = _ghostLevel;	}
		char getGhostLevel() { return ghostLevel; }

		//----------Methods-----------//
		char menu();
		char levelMenu();
		void chooseBoard();
		//void checkFileInput(bool& isValidFile);

		void getInput(bool& flag);
		void runGame();
		void run();
		void runScreen(bool& didILose);
		
		void creaturesCollision(bool& didILose, bool& fruitActive);
		void winGame();
		void gameOver();
		void resetGame(string screen, bool& isValidFile);
		void initScreens();

		void printMenu();
		void printInstractions();
		void printLevelMenu();
		void printGamePause();
		void printPacmanSign();
		void printExit();
		void printMsg(string s);

private:
		bool collision(const Creature& A, const Creature& B);
		void ghostPacmanCollision(bool& didILose);
		void fruitPacmanCollision(bool& fruitActive);
		void hideFruit(bool& fruitActive);
};

#endif