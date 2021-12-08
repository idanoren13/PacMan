#ifndef BOARD_H_
#define BOARD_H_

#include "Point.h"

#define WIDTH 43 
#define HEIGHT 17 
#define MAX_SCORE 300 

// Move to Game_Logic.h
enum Shape { FIVE = '5', SIX = '6', SEVEN = '7', EIGHT = '8', NINE = '9', PACMAN = '@', GHOST = '&', BREAD = 250, WALL = 178 };

class Board {
	enum board_chars{ wa = 178, br = 250}; // wall & bread
	unsigned char board[HEIGHT][WIDTH] =
	{
		{' '},
		{' ', wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, ' ', ' ', wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa },
		{' ', wa, wa, br, br, br, br, br, br, br, br, wa, wa, br, br, br, br, br, br, wa, wa, ' ', ' ', wa, wa, br, br, br, br, br, br, wa, wa, br, br, br, br, br, br, br, br, wa, wa },
		{' ', wa, wa, br, br, wa, wa, wa, wa, br, br, wa, wa, br, br, wa, wa, br, br, wa, wa, ' ', ' ', wa, wa, br, br, wa, wa, br, br, wa, wa, br, br, wa, wa, wa, wa, br, br, wa, wa },
		{' ', wa, wa, br, br, wa, wa, wa, wa, br, br, wa, wa, br, br, wa, wa, br, br, br, br, br, br, br, br, br, br, wa, wa, br, br, wa, wa, br, br, wa, wa, wa, wa, br, br, wa, wa },
		{' ', wa, wa, br, br, wa, wa, br, br, br, br, wa, wa, br, br, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, br, br, wa, wa, br, br, br, br, wa, wa, br, br, wa, wa },
		{' ', wa, wa, br, br, wa, wa, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, wa, wa, br, br, wa, wa },
		{' ', wa, wa, br, br, wa, wa, br, br, br, br, wa, wa, br, br, br, wa, wa, ' ', ' ', ' ', ' ', ' ', ' ', ' ',  ' ', wa, wa, br, br, br, wa, wa, br, br, br, br, wa, wa, br, br, wa, wa },
		{' ', wa, wa, br, br, br, br, br, br, br, wa, wa, wa, wa, br, br, wa, wa, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', wa, wa, br, br, wa, wa, wa, wa, br, br, br, br, br, br, br, wa, wa },
		{' ', ' ', ' ', br, br, br, br, br, br, br, br, br, br, br, br, br, wa, wa, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', wa, wa, br, br, br, br, br, br, br, br, br, br, br, br, br, ' ', ' ' },
		{' ', wa, wa, br, br, wa, wa, br, br, br, wa, wa, wa, wa, br, br, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, br, br, wa, wa, wa, wa, br, br, br, wa, wa, br, br, wa, wa },
		{' ', wa, wa, br, br, wa, wa, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, wa, wa, br, br, wa, wa },
		{' ', wa, wa, br, br, wa, wa, br, br, br, br, wa, wa, br, br, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, br, br, wa, wa, br, br, br, br, wa, wa, br, br, wa, wa },
		{' ', wa, wa, br, br, wa, wa, wa, wa, br, br, wa, wa, br, br, wa, wa,' ', ' ', 'P','a','c','M','a','n',' ', ' ', wa, wa, br, br, wa, wa, br, br, wa, wa, wa, wa, br, br, wa, wa },
		{' ', wa, wa, br, br, wa, wa, wa, wa, br, br, wa, wa, br, br, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, br, br, wa, wa, br, br, wa, wa, wa, wa, br, br, wa, wa },
		{' ', wa, wa, br, br, br, br, br, br, br, br, wa, wa, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, wa, wa, br, br, br, br, br, br, br, br, wa, wa },
		{' ', wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, ' ', ' ', wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa }
	};

public:
	void initBoard();
	void printBoard(bool black_and_white);
	char getCell(Point p);
	void editCell(Point p, char ch);
	void printData(int score, int life);

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
