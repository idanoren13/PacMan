#pragma once
#include "Game_Logic.h"
#include "Print_Manager.h"
#include <sstream>
#include <string>


class Load_Mode : public Game_Logic
{
	int slowCreature = 0;
	bool silent;
	bool fruitActive;
	
private:
	Move_Vector char2Vector(char ch);

public:
	//--------Constructors--------//
	Load_Mode();
	Load_Mode(bool _silent);


	//-----Setters & Getters------//

	//----------Methods-----------//

	virtual void runGame(bool s);
	virtual void run();
	virtual void runScreen(bool& didILose);
	void resetGame(string screen);
	void decodeLine(string line);

	void compareResults(std::string fileName);

	void runSilentMode();

};

