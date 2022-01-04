#ifndef FRUIT_H_
#define FRUIT_H_

#include "Point.h"
#include "Color.h"
#include "Board.h"
#include "Creature.h"

class Fruit : public Creature {
	//int move_cntr;

public:

	//--------Constructors--------//
	Fruit() : Creature(Point(21, 8), BROWN, FIVE, UP){ setShape(Shape(53 + rand() % 5)); }
	Fruit(Point _p) : Creature(_p, BROWN, FIVE, UP) { setShape(Shape(rand() % 5)); }
	Fruit(Point _p, Color _color) : Creature(_p, _color, FIVE, UP) { setShape(Shape(rand() % 5)); }

	//-----Setters & Getters------//
	void setFruit(Point p, Board& board);

	//----------Methods-----------//
	void virtual move(Board& board);
	//void hideFruit(Board& board);
	//void controledMove(Board& board);
	//char getValue() { return getShape(); }
	void printFruit(Board& board);

};

#endif

