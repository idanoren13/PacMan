#ifndef BOARD_H_
#define BOARD_H_

#include "Point.h"
#include "io_utils.h"
#include <fstream>

using std::string;
using std::ifstream;
using std::ios;

#define MAX_COLS 80 
#define MAX_ROWS 25 

// Move to Game_Logic.h
enum Shape { FIVE = '5', SIX = '6', SEVEN = '7', EIGHT = '8', NINE = '9', PACMAN = '@', GHOST = '&', BREAD = 250, WALL = 178 };

class Board {

	unsigned char board[MAX_ROWS][MAX_COLS];
	int height, width;
	int num_of_bread_crumbs;
	int num_of_ghosts;

	Point legendPos;
	Point pacmanPos;
	Point ghostsPos[4];

public:

	//-----Constructors--------//

	Board();

	//-----Setters & Getters------//

	void editCell(Point p, char ch);
	void resetBoard() { num_of_bread_crumbs = num_of_ghosts = 0; }
	
	unsigned char getCell(Point p);
	int getHeight() { return height; }
	int getWidth() { return width; }
	int getNumOfCrumbs() { return num_of_bread_crumbs; }
	int getNumOfGhosts() { return num_of_ghosts; }

	Point getLegendPos() { return legendPos; }
	Point getPacmanPos() { return pacmanPos; }
	Point* getGhostsPos() { return ghostsPos; }
	
	//----------Methods-----------//

	Point getRandomPoint();

	void initBoard(const char* filename, bool& isValidFile, string& errMsg);
	void handleRead(const char read, int& row, int& col, int& countChars);
	void initLegend();
	void printBoard(bool black_and_white);
	void printData(int score, int life);

	bool isPointValid(Point _p) {
		return (_p.getY() < height) && (_p.getY() >= 0) && (_p.getX() < width) && (_p.getX() >= 0);
	}

//private:
//	enum board_chars { wa = 178, br = 250 }; // wall & bread
//	unsigned char defaultBoard[17][43] =
//	{
//		{' '},
//		{' ', wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, ' ', ' ', wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa },
//		{' ', wa, wa, br, br, br, br, br, br, br, br, wa, wa, br, br, br, br, br, br, wa, wa, ' ', ' ', wa, wa, br, br, br, br, br, br, wa, wa, br, br, br, br, br, br, br, br, wa, wa },
//		{' ', wa, wa, br, br, wa, wa, wa, wa, br, br, wa, wa, br, br, wa, wa, br, br, wa, wa, ' ', ' ', wa, wa, br, br, wa, wa, br, br, wa, wa, br, br, wa, wa, wa, wa, br, br, wa, wa },
//		{' ', wa, wa, br, br, wa, wa, wa, wa, br, br, wa, wa, br, br, wa, wa, br, br, br, br, br, br, br, br, br, br, wa, wa, br, br, wa, wa, br, br, wa, wa, wa, wa, br, br, wa, wa },
//		{' ', wa, wa, br, br, wa, wa, br, br, br, br, wa, wa, br, br, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, br, br, wa, wa, br, br, br, br, wa, wa, br, br, wa, wa },
//		{' ', wa, wa, br, br, wa, wa, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, wa, wa, br, br, wa, wa },
//		{' ', wa, wa, br, br, wa, wa, br, br, br, br, wa, wa, br, br, br, wa, wa, ' ', ' ', ' ', ' ', ' ', ' ', ' ',  ' ', wa, wa, br, br, br, wa, wa, br, br, br, br, wa, wa, br, br, wa, wa },
//		{' ', wa, wa, br, br, br, br, br, br, br, wa, wa, wa, wa, br, br, wa, wa, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', wa, wa, br, br, wa, wa, wa, wa, br, br, br, br, br, br, br, wa, wa },
//		{' ', ' ', ' ', br, br, br, br, br, br, br, br, br, br, br, br, br, wa, wa, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', wa, wa, br, br, br, br, br, br, br, br, br, br, br, br, br, ' ', ' ' },
//		{' ', wa, wa, br, br, wa, wa, br, br, br, wa, wa, wa, wa, br, br, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, br, br, wa, wa, wa, wa, br, br, br, wa, wa, br, br, wa, wa },
//		{' ', wa, wa, br, br, wa, wa, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, wa, wa, br, br, wa, wa },
//		{' ', wa, wa, br, br, wa, wa, br, br, br, br, wa, wa, br, br, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, br, br, wa, wa, br, br, br, br, wa, wa, br, br, wa, wa },
//		{' ', wa, wa, br, br, wa, wa, wa, wa, br, br, wa, wa, br, br, wa, wa,' ', ' ', 'P','a','c','M','a','n',' ', ' ', wa, wa, br, br, wa, wa, br, br, wa, wa, wa, wa, br, br, wa, wa },
//		{' ', wa, wa, br, br, wa, wa, wa, wa, br, br, wa, wa, br, br, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, br, br, wa, wa, br, br, wa, wa, wa, wa, br, br, wa, wa },
//		{' ', wa, wa, br, br, br, br, br, br, br, br, wa, wa, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, wa, wa, br, br, br, br, br, br, br, br, wa, wa },
//		{' ', wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, ' ', ' ', wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa }
//	};
};

#endif


//{' '},
// 01234567890123456789012345678901234567890123456789 = 42 * 17
//{ ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓}
//{ ▓▓········▓▓······▓▓  ▓▓······▓▓········▓▓}
//{ ▓▓··▓▓▓▓··▓▓··▓▓··▓▓  ▓▓··▓▓··▓▓··▓▓▓▓··▓▓}
//{ ▓▓··▓▓▓▓··▓▓··▓▓··········▓▓··▓▓··▓▓▓▓··▓▓}
//{ ▓▓··▓▓····▓▓··▓▓▓▓▓▓▓▓▓▓▓▓▓▓··▓▓····▓▓··▓▓}
//{ ▓▓··▓▓······························▓▓··▓▓}
//{ ▓▓··▓▓····▓▓···▓▓▓      ▓▓▓···▓▓····▓▓··▓▓}
//{ ▓▓·······▓▓▓▓··▓▓        ▓▓··▓▓▓▓·······▓▓}
//{   ·············▓▓        ▓▓·············  }10,21,22
//{ ▓▓··▓▓···▓▓▓▓··▓▓▓▓▓▓▓▓▓▓▓▓··▓▓▓▓···▓▓··▓▓}
//{ ▓▓··▓▓······························▓▓··▓▓}
//{ ▓▓··▓▓····▓▓··▓▓▓▓▓▓▓▓▓▓▓▓▓▓··▓▓····▓▓··▓▓}
//{ ▓▓··▓▓▓▓··▓▓··▓▓▓ PacMan ▓▓▓··▓▓··▓▓▓▓··▓▓}
//{ ▓▓··▓▓▓▓··▓▓··▓▓▓▓▓▓▓▓▓▓▓▓▓▓··▓▓··▓▓▓▓··▓▓}
//{ ▓▓········▓▓··················▓▓········▓▓}
//{ ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓}

