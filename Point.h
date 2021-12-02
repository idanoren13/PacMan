#ifndef _POINT_H_
#define _POINT_H_

#include "io_utils.h"

enum Move_Vector { UP, RIGHT, DOWN, LEFT, STAY };

class Point {
	int x, y;

public:
	Point();
	Point(int _x, int _y) : x(_x), y(_y) {}
	void setPoint(int x, int y);
	int getX();
	int getY();
	void draw(char ch);
	void move();
	void move(int direction);
	bool isSamePoint(const Point p1);
};

#endif