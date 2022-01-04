#pragma once
#include "Game_Logic.h"
#include "Print_Manager.h"
#include <sstream>
#include <string>

class Load_Mode : public Game_Logic
{
	//singleton ivan;
	//singleton& boris = singleton::get();
	bool silent;
	bool fruitActive;
private:
	void compareResults(std::string fileName);
	
public:
	//--------Constructors--------//
	Load_Mode();
	Load_Mode(bool _silent);


	//-----Setters & Getters------//

	//----------Methods-----------//
	virtual void runGame();
	//virtual void run();
	virtual void runScreen(bool& didILose);
	void resetGame(string screen);
	void decodeLine(string line);
};

