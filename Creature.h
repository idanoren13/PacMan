#ifndef _CREATURE_H_
#define _CREATURE_H_

#include "Point.h"
#include "Color.h"
#include "Board.h"
#include "io_utils.h"
#include "Print_Manager.h"


class Creature
{
	char shape;
	Color color;

protected:

	int move_cntr;
	Move_Vector v;
	Point curr_point;
	Point next_point;
	Point prev_point;
	//Print_Manager& printer;

public:

	//--------Constructors--------//
	Creature(Point _p, Color _color, Shape _shape, Move_Vector _v);

	//----------Setters-----------//
	void setColor(Color c) { color = c; }
	void setShape(Shape _shape) { shape = _shape; }
	void setVector(Move_Vector dir) { v = dir; }
	void setCurrPoint(Point _p) { curr_point = _p; }
	void setNextPoint(Point _p) { next_point = _p; }

	//----------Getters-----------//
	char getShape() const { return shape; }
	Move_Vector getVector() const { return v; }
	Point getCurrPoint() const { return curr_point; }
	Point getPrevPoint() const { return prev_point; }


	//----------Methods-----------//
	virtual void move(Board& board) = 0;	// make Creature an abstract class
	void controledMove(Board& board);
	void printCreature();
	bool isEndBoard(int height, int width);
};

#endif

