#ifndef FRUIT_H_
#define FRUIT_H_

#include "Point.h"
#include "Color.h"
#include "Board.h"
#include "Creature.h"

class Fruit : public Creature {
	int move_cntr;

public:
	//enum class fShape { FIVE = '5', SIX, SEVEN, EIGHT, NINE };

	//--------Constructors--------//
	Fruit() : Creature(Point(21, 9), DARKGREY, FIVE, UP), move_cntr(0) { setShape(Shape(53 + rand() % 5)); }
	Fruit(Point _p) : Creature(_p, DARKGREY, FIVE, UP), move_cntr(0) { setShape(Shape(rand() % 5)); }
	Fruit(Point _p, Color _color) : Creature(_p, _color, FIVE, UP), move_cntr(0) { setShape(Shape(rand() % 5)); }

	//-----Setters & Getters------//
	void setFruit(Point p, Board& board);

	//----------Methods-----------//
	void move(Board& board);
	bool isEndBoard(int height, int width);
};

#endif

