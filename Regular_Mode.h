#pragma once
#include "Game_Logic.h"

class Regular_Mode : public Game_Logic
{
private:
	bool save_mode;
	char ghostLevel;
	int point_of_time;
	bool continue_game = true;

public:

	//--------Constructors--------//
	Regular_Mode() : ghostLevel('c') {}

	//-----Setters & Getters------//
	void setGhostLevel(char _ghostLevel) { ghostLevel = _ghostLevel; }
	char getGhostLevel() { return ghostLevel; }

	//----------Methods-----------//
	virtual void runGame(bool _save_mode);
	virtual void runScreen(bool& didILose);
	void run();

	void resetGame(string screen);
	void chooseBoard();
	char menu();
	char levelMenu();
};


