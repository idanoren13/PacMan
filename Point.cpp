#include "Point.h"

Point::Point() {
	setPoint(0, 0);
}


void Point::setPoint(int _x, int _y) {
	x = _x;
	y = _y;
}

int Point::getX() {
	return x;
}

int Point::getY() {
	return y;
}

void Point::draw(char ch) {
	gotoxy(x, y);
	cout << ch << endl;
}

void Point::move() {
	int dir = rand() % 4;
	move(dir);
}


void Point::move(int dir) {
	switch (dir) {
	case 0: // UP
		--y;
		break;
	case 1: // RIGHT
		++x;
		break;
	case 2: // DOWN
		++y;
		break;
	case 3: // LEFT
		--x;
		break;
	}
}

bool Point::isSamePoint(const Point p1)const {
	return (x == p1.x) && (y == p1.y);
}


