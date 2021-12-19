#include "Creature.h"

//--------Constructors--------//

Creature::Creature(Point _p, Color _color, Shape _shape, Move_Vector _v) {
	prev_point = next_point = curr_point = _p;
	color = _color;
	shape = (char)_shape;
	v = _v;
}


//----------Methods-----------//

void Creature::printCreature() {
	setTextColor(color);
	curr_point.draw(shape);
}

//bool Creature::isEndBoard() {
//	return (next_point.getX() > WIDTH - 2 || next_point.getX() < 1 || next_point.getY() > HEIGHT - 1 || next_point.getY() < 1);
//}

