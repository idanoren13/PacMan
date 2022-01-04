#pragma once
#include "File_handler.h"


class Text_Printer
{
	bool silent;

public:

	//--------Constructors--------//
	Text_Printer() : silent(false) {}
	Text_Printer(bool _silent) : silent(_silent) {}

	//-----Setters & Getters------//
	void setSilentMode(bool _silent) { silent = _silent; }

	//----------Methods-----------//
	void printObj(Point p, char c);
	void printMenu();
	void printGamePause(int height);
	void printInstractions();
	void printLevelMenu();

	void printExit();
	void printPacmanSign();
	void printMsg(string s);

};

