#ifndef GHOST_H_
#define GHOST_H_

#include "Point.h"
#include "Color.h"
#include "Board.h"
#include "Creature.h"
#include <queue>
#include <stdlib.h>

class Ghost : public Creature {
	int move_cntr;
	char level;
	Point pacmanPoint;

public:
	//--------Constructors--------//

	Ghost() : Creature(Point(21,9), WHITE, GHOST, UP), move_cntr(0) {}
	Ghost(Point _p) : Creature(_p, WHITE, GHOST, UP), move_cntr(0) {}
	Ghost(Point _p, Color _color) : Creature(_p, _color, GHOST, UP), move_cntr(0) {}

	//-----Setters & Getters------//
	void setGhost(Point p, Board & board);
	void setPacmanPoint(Point _p) { pacmanPoint = _p; }
	void setGhostLevel(char _level) {level = _level;}

	//----------Methods-----------//
	
	void virtual move(Board& board);
	void smartMove(Board& board);
	void avgMove(Board& board);
	void dumbMove(Board& board);
	void printGhost(Board& board);

private:
	bool isNextToCurrPoint(Point _p);
	bool isValidMove(Board& board, Point point);
};

#endif

