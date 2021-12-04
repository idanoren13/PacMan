#ifndef GHOST_H_
#define GHOST_H_

#include "Point.h"
#include "Color.h"
#include "Board.h"
#include "Creature.h"

class Ghost : public Creature {
	int move_cntr;

public:
	//--------Constructors--------//
	Ghost() : Creature(Point(21,9), WHITE, GHOST, UP), move_cntr(0) {}
	Ghost(Point _p) : Creature(_p, WHITE, GHOST, UP), move_cntr(0) {}
	Ghost(Point _p, Color _color) : Creature(_p, _color, GHOST, UP), move_cntr(0) {}

	//-----Setters & Getters------//
	void setGhost(Point p, Board & board);

	//----------Methods-----------//
	void moveGhost(Board& board);
	bool isEndBoard();
};

#endif

