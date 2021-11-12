#include "Ghost.h"

//--------Constructors---------------------------------//

Ghost::Ghost() {
	curr_point.setPoint(15,5);
	color = RED;
	shape = (char)GHOST;
	v = STAY;
}

Ghost::Ghost(Point _p, Color c) {
	curr_point.setPoint(_p.getX(), _p.getY());
	color = c;
	shape = (char)GHOST;
	v = STAY;
}

Ghost::~Ghost() { delete this; }

//--------Getters and Setters---------------------------//

void Ghost::setGhost(Point p) {curr_point.setPoint(p.getX(), p.getY());}

Point Ghost::getGhost() {return curr_point;}

//--------Methods------------------------------------//

void Ghost::moveGhost(Board& board) { // cancel blackHole passing option
	next_point = curr_point;
	next_point.move();
	unsigned char readVal = board.getCell(next_point);
	switch (readVal) {
	case (unsigned char)WALL:
		v = STAY;
		return;
	case (unsigned char)BREAD:
		setTextColor(Color::LIGHTCYAN);
		curr_point.draw((unsigned char)BREAD);
		break;
	case (unsigned char)PACMAN:
		clear_screen();
		gotoxy(0, 0);
		cout << "YOU LOSE" << endl;
	default:
		curr_point.draw(' ');
		break;
	}
	curr_point = next_point;
	printGhost();
}

void Ghost::printGhost() {
	setTextColor(color);
	curr_point.draw(shape);
}