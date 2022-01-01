#pragma once
#include "Game_Logic.h"


class Regular_Mode : public Game_Logic
{
private:
	bool save_mode;
	char ghostLevel;
	int point_of_time;

public:

	//--------Constructors--------//
	Regular_Mode() : ghostLevel('c') {}

	//-----Setters & Getters------//
	void setGhostLevel(char _ghostLevel) { ghostLevel = _ghostLevel; }
	char getGhostLevel() { return ghostLevel; }

	//----------Methods-----------//
	virtual void runGame(bool _save_mode);
	virtual void run();
	virtual void runScreen(bool& didILose, bool& continue_game);

	char menu();
	char levelMenu();

	void chooseBoard();
	void printMenu();
	void printInstractions();
	void printLevelMenu();
	void printGamePause();

};


