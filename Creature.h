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
	void setShape(Shape _shape) { shape = _shape; }
	void setVector(Move_Vector dir) { v = dir; }

	//----------Getters-----------//
	char getShape() const { return shape; }
	Move_Vector getVector() const { return v; }
	Point getCurrPoint() const { return curr_point; }
	Point getPrevPoint() const { return prev_point; }

	//----------Methods-----------//
	void printCreature();
	virtual void move(Board& board) = 0;	// make Creature an abstract class
	//virtual bool isEndBoard();
};

#endif

