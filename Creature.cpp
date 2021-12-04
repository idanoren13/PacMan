#include "Creature.h"

//--------Constructors--------//

Creature::Creature(Point _p, Color _color, Shape _shape, Move_Vector _v) {
	curr_point.setPoint(_p.getX(), _p.getY());
	color = _color;
	shape = (char)_shape;
	v = _v;
}

//------Setters & Getters-------//
//void Creature::setCreature(Point p, Board& board)

	//----------Methods-----------//
//void Creature::moveCreature(Board& board)

void Creature::printCreature() {
	setTextColor(color);
	curr_point.draw(shape);
}

//bool Creature::isEndBoard() {
//	return (next_point.getX() > WIDTH - 2 || next_point.getX() < 1 || next_point.getY() > HEIGHT - 1 || next_point.getY() < 1);
//}

