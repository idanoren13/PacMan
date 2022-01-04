#pragma once
#include "File_handler.h"

// Singleton Class
class Text_Printer
{
	bool silent = false;
	Text_Printer() {}

public:
	Text_Printer(const Text_Printer&) = delete;

	static Text_Printer& Get() {
		static Text_Printer printer;
		return printer;
	}
	void operator=(Text_Printer const&) = delete;

	//-----Setters & Getters------//
	void setSilent(bool _silent) { silent = _silent; }

	//----------Methods-----------//

	void printData(int score, int life, Point legendPos);
	void printMenu();
	void printGamePause(int height);
	void printInstractions();
	void printLevelMenu();

	void printExit();
	void printPacmanSign();
	void printMsg(string s);

};

