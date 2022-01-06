#pragma once
#include "Game_Logic.h"
#include "Text_Printer.h"
#include <sstream>
#include <string>


class Load_Mode : public Game_Logic
{
	bool silent;
	bool fruitActive;

public:
	//--------Constructors--------//
	Load_Mode(bool _silent);

	//-----Setters & Getters------//

	//----------Methods-----------//

	virtual void runGame();
	virtual void runScreen(bool& didILose);

	void resetGame(string screen);
	void decodeLine(string line);

	void compareResults(std::string fileName);
	void runSilentMode();
};

