#pragma once
#include <string>
#include <iostream>
#include "Point.h"

// Singleton Class
class Print_Creature
{
private:
	bool silent = false;
	Print_Creature() {}

public:

	Print_Creature(const Print_Creature&) = delete;
	void operator=(Print_Creature const&) = delete;

	static Print_Creature& Get() {
		static Print_Creature printer;
		return printer;
	}

	void printObj(Point _p, char ch);
	void setSilent(const bool _s) { silent = _s; }

};
