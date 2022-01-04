#pragma once
#include <string>
#include <iostream>
#include "Point.h"

// Singleton Class
class Print_Creature
{

private:
	bool silent;
	Print_Creature() {}

public:
	static Print_Creature& get() {
		static Print_Creature printer;
		return printer;
	}

	void operator=(Print_Creature const&) = delete;

	void printObj(Point _p, char ch);
	void setSilent(const bool _s) { silent = _s; }

};
