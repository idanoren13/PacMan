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

char Creature::getVectorInChar() {
	char ch;
	switch (v)
	{
	case UP:
		ch = 'u';
		break;
	case DOWN:
		ch = 'd';
		break;
	case LEFT:
		ch = 'l';
		break;
	case RIGHT:
		ch = 'r';
		break;
	case STAY:
		ch = 's';
		break;
	default:
		ch = 0;
		break;
	}
	return ch;
}

void Creature::controledMove(Board& board) {
	//next_point.move(v);
	setTextColor(Color::LIGHTGREY);
	curr_point.draw(board.getCell(curr_point));
	curr_point = next_point;
	printCreature();
}