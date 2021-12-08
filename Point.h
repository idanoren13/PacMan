#ifndef _POINT_H_
#define _POINT_H_

#include "io_utils.h"

enum Move_Vector { UP, RIGHT, DOWN, LEFT, STAY };

class Point {
	int x, y;

public:
	//--------Constructors--------//
	Point();
	Point(int _x, int _y) : x(_x), y(_y) {}

	//-----Setters & Getters------//
	void setPoint(int x, int y);
	int getX();
	int getY();

	//----------Methods-----------//
	void draw(char ch);
	void move();
	void move(int direction);
	bool isSamePoint(const Point p1)const;
};

#endif