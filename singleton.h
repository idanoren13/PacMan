#pragma once
#include <string>
#include <iostream>
#include "Point.h"

class singleton
{
	//Board board;

private:
	bool silent;

	singleton() {}

public:
	static singleton& get() {
		static singleton printer;
		return printer;
	}

	void operator=(singleton const&) = delete;

	//template <class T>
	//void print(const T& t, Board& board);
	void printObj(Point _p, Color color, char ch);
	void setSilent(const bool _s) { silent = _s; }
	//void setBoard(const Board& _b) { board = _b; }
//private:
//	void printCreature(Creature c);
//	void printPacman(Pacman pacman);
//	void printPoint(Point _p);

};

