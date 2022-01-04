#include "Creature.h"

//--------Constructors--------//

Creature::Creature(Point _p, Color _color, Shape _shape, Move_Vector _v) {
	int move_cntr=0;
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

bool Creature::isEndBoard(int height, int width) {
	return (next_point.getX() > width - 2 || next_point.getX() < 0 || next_point.getY() > height - 2 || next_point.getY() < 0);
}

void Creature::controledMove(Board& board) {
	prev_point = curr_point;
	setTextColor(Color::LIGHTGREY);
	curr_point.draw(board.getCell(curr_point));
	curr_point = next_point;
	//singleton::get().printObj(curr_point, color, shape);
	printCreature();

}