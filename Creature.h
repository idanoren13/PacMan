#ifndef _CREATURE_H_
#define _CREATURE_H_

#include "Point.h"
#include "Color.h"
#include "Board.h"
#include "io_utils.h"

class Creature
{
	char shape;
	Color color;
	Move_Vector v;

	Point curr_point;
	Point next_point;
	Point prev_point;

public:

	//--------Constructors--------//
	Creature(Point _p, Color _color, Shape _shape, Move_Vector _v);

	//-----Setters & Getters------//
	Point getCreature() { return curr_point; }
	Point getPrevCreature() { return prev_point; }
	char getShape() { return shape; }

	//void setCreature(Point p, const Board& board);
	void setColor(Color c) { color = c; }
	void setVector(Move_Vector dir) { v = dir; }

	//----------Methods-----------//
	//void moveCreature(Board& board);
	void printCreature();

private:
	bool isEndBoard();
};

#endif

