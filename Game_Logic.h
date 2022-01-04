#ifndef GAME_LOGIC_H_
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
#include "Text_Printer.h"
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

class Game_Logic {

protected:
	Print_Creature& boris = Print_Creature::get();
	int slowCreature = 0;
	Board board;
	Pacman pacman;
	Fruit fruit;
	std::vector<Ghost> ghosts;
	std::vector<string> screenNames;

	bool black_and_white;
	string fileName = "";

	File_handler my_stream;
	Text_Printer printer;

public:
		//--------Constructors--------//
		Game_Logic();

		//----------Methods-----------//
		virtual void runGame(bool s) = 0;
		virtual void runScreen(bool& didILose) = 0;

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
};
#endif