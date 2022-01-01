﻿#ifndef BOARD_H_
#define BOARD_H_

#include "Point.h"
#include "io_utils.h"
#include <fstream>

using std::string;
using std::ifstream;
using std::ios;

#define MAX_COLS 80
#define MAX_ROWS 25 

// Change to enum class
enum Shape { FIVE = '5', SIX = '6', SEVEN = '7', EIGHT = '8', NINE = '9', PACMAN = '@', GHOST = '&', BREAD = 250, WALL = 178 };

class Board {

	unsigned char board[MAX_ROWS][MAX_COLS];
	int height, width;
	int num_of_bread_crumbs;
	int num_of_ghosts;

	Point legendPos;
	Point pacmanPos;
	Point ghostsPos[4];

	bool validScreen = true;
	bool initPacman = false;
	bool initLegend = false;
	string errMsg;

public:

	//-----Constructors--------//

	Board() : height(0), width(0), num_of_bread_crumbs(0), num_of_ghosts(0) {}

	//-----Setters & Getters------//

	void editCell(Point p, char ch);
	
	unsigned char getCell(Point p);
	int getHeight() { return height; }
	int getWidth() { return width; }
	int getNumOfCrumbs() { return num_of_bread_crumbs; }
	int getNumOfGhosts() { return num_of_ghosts; }

	Point getLegendPos() { return legendPos; }
	Point getPacmanPos() { return pacmanPos; }
	Point* getGhostsPos() { return ghostsPos; }
	string getErrMsg() { return errMsg; }
	
	//----------Methods-----------//

	Point getRandomPoint();

	void initBoard(const char* filename);
	void handleRead(const char read, int& row, int& col, int& countChars);
	void initiateLegend();
	void printBoard(bool black_and_white);
	void printData(int score, int life);

	bool isValidScreen(){ return isValidScreen; }
	bool isPointValid(Point _p) {
		return (_p.getY() < height) && (_p.getY() >= 0) && (_p.getX() < width) && (_p.getX() >= 0);
	}

private:
	void resetBoard();

};

#endif

