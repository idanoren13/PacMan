#pragma once
#include "Game_Logic.h"


class Load_Mode : public Game_Logic
{

public:

	//----------Methods-----------//

	virtual void runGame(bool silent);
	virtual void run();
	virtual void runScreen(bool& didILose, bool& continue_game);

	void runSilentMode();

};

