#ifndef GHOST_H_
#define GHOST_H_

#include "Point.h"
#include "Color.h"
#include "Board.h"
#include "Creature.h"
#include <queue>

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
	void move(Board& board, Creature& pacman, char level);
	void smartMove(Board& board, Creature& pacman);
	void avgMove(Board& board);
	void dumbMove(Board& board);

	bool isEndBoard(int height, int width);

	Point move(Board& board, Creature& ghost, Creature& pacman);
	bool isEndBoard(int height, int width, Point point);
	bool isValidMove(Board& board, Point point);
};

#endif

