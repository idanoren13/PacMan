#ifndef GHOST_H_
#define GHOST_H_

#include "Point.h"
#include "Color.h"
#include "Board.h"
#include "Creature.h"
#include <queue>

class Ghost : public Creature {
	int move_cntr;
	char level;

public:
	//--------Constructors--------//
	Ghost() : Creature(Point(21,9), WHITE, GHOST, UP), move_cntr(0) {}
	Ghost(Point _p) : Creature(_p, WHITE, GHOST, UP), move_cntr(0) {}
	Ghost(Point _p, Color _color) : Creature(_p, _color, GHOST, UP), move_cntr(0) {}

	//-----Setters & Getters------//
	void setGhost(Point p, Board & board);
	void setGhostLevel(char _level) {level = _level;}

	//----------Methods-----------//

	void move(Board& board, Creature& pacman);
	void smartMove(Board& board, Creature& pacman);
	void avgMove(Board& board);
	void dumbMove(Board& board);
	void printGhost(Board& board);


	//bool isEndBoard(int height, int width, Point point);
	bool isValidMove(Board& board, Point point);
	bool isEndBoard(int height, int width);
};

#endif

