#pragma once
#include "Game_Logic.h"

class Regular_Mode : public Game_Logic
{
private:
	bool save_mode;
	char ghostLevel;
	bool continue_game = true;

public:

	//--------Constructors--------//
	Regular_Mode(bool _save_mode) : ghostLevel('c'), save_mode(_save_mode) {}

	//-----Setters & Getters------//
	void setGhostLevel(char _ghostLevel) { ghostLevel = _ghostLevel; }
	char getGhostLevel() { return ghostLevel; }

	//----------Methods-----------//
	virtual void runGame();
	virtual void runScreen(bool& didILose);
	void run();

	void resetGame(string screen);
	void chooseBoard();
	char menu();
	char levelMenu();
};


