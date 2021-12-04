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

protected:

	Move_Vector v;
	Point curr_point;
	Point next_point;
	Point prev_point;

	//void setCreature(Point p, const Board& board);

public:

	//--------Constructors--------//
	Creature(Point _p, Color _color, Shape _shape, Move_Vector _v);

	//----------Setters-----------//
	void setColor(Color c) { color = c; }
	void setPrevPoint(Point p) { prev_point = p; }
	void setVector(Move_Vector dir) { v = dir; }

	//----------Getters-----------//
	char getShape() { return shape; }
	Move_Vector getVector() { return v; }
	Point getCurrPoint() { return curr_point; }
	Point getPrevPoint() { return prev_point; }

	//----------Methods-----------//
	//void moveCreature(Board& board);
	void printCreature();
	//bool isEndBoard();
};

#endif

