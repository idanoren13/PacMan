#ifndef GAME_LOGIC_H__
#define GAME_LOGIC_H_
#define _CRT_SECURE_NO_WORNINGS

#include "Pacman.h"
#include "Ghost.h"
#include "Fruit.h"

#include "Point.h"
#include "Board.h"
#include "Color.h"

#include "io_utils.h"
#include "File_handler.h"
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

class Game_Logic {

private:

protected:

	Board board;
	Pacman pacman;
	Fruit fruit;
	std::vector<Ghost> ghosts;
	std::vector<string> screenNames;

	bool black_and_white;
	string fileName = "";
	File_handler my_stream;


public:
		//--------Constructors--------//
		Game_Logic();

		//----------Methods-----------//
		virtual void runGame() = 0;
		virtual void run() = 0;
		virtual void runScreen(bool& didILose, bool& continue_game) = 0;

		void getInput(bool& flag, bool& continue_game);

		void creaturesCollision(bool& didILose, bool& fruitActive);
		void resetGame(string screen);
		void readScreens();
		void initScreens();
		void winGame();
		void gameOver();

		bool collision(const Creature& A, const Creature& B);
		void ghostPacmanCollision(bool& didILose);
		void fruitPacmanCollision(bool& fruitActive);
		void hideFruit(bool& fruitActive);

		void printExit();
		void printPacmanSign();
		void printMsg(string s);
};
#endif