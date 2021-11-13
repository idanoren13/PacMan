﻿#ifndef BOARD_H_
#define BOARD_H_

#include "Point.h"
#define NUM_OF_BARRIES 50

#define WIDTH 31
#define HEIGHT 12
#define MAX_SCORE 65

#define W (char)(178)<<	//wall
#define O (char)(250)<<	//bread

class Board {
	unsigned char board[HEIGHT][WIDTH] =
	{
		{ ' '},
		{ 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178},
		{ 178, 250, 250, 250, 250, 250, 250, 178, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 178, 250, 250, 250, 250, 250, 250, 178 },
		{ 178, 250, 178, 178, 178, 250, 250, 178, 250, 250, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 250, 250, 178, 250, 250, 178, 178, 178, 250, 178 },
		{ 178, 250, 178, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 178, 250, 178 },
		{ 178, 250, 178, 250, 250, 178, 178, 178, 250, 250, 178, 178, ' ',' ',' ',' ',' ',' ', 178, 178, 250, 250, 178, 178, 178, 250, 250, 178, 250, 178 },
		{ ' ',250 ,250, 250, 250, 250, 250, 250, 250, 250, 178,' ',' ',' ',' ',' ',' ',' ',' ',178,250,250,250,250,250,250,250,250,250 },
		{ 178, 250, 178, 250, 250, 178, 178, 178, 250, 250, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 250, 250, 178, 178, 178, 250, 250, 178, 250, 178},
		{ 178, 250, 178, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 178, 250, 178 },
		{ 178, 250, 178, 178, 178, 250, 250, 178, 250, 250, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 250, 250, 178, 250, 250, 178, 178, 178, 250, 178 },
		{ 178, 250, 250, 250, 250, 250, 250, 178, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 178, 250, 250, 250, 250, 250, 250, 178 },
		{ 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178 }
		/*
		{ '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓'},
		{ '▓', '·', '·', '·', '·', '·', '·', '▓', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '▓', '·', '·', '·', '·', '·', '·', '▓' },
		{ '▓', '·', '▓', '▓', '▓', '·', '·', '▓', '·', '·', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '·', '·', '▓', '·', '·', '▓', '▓', '▓', '·', '▓' },
		{ '▓', '·', '▓', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '▓', '·', '▓' },
		{ '▓', '·', '▓', '·', '·', '▓', '▓', '▓', '·', '·', '▓', '▓', ' ',' ',' ',' ',' ',' ', '▓', '▓', '·', '·', '▓', '▓', '▓', '·', '·', '▓', '·', '▓' },
		{ ' ',' ','·' ,'·', '·', '·', '·', '·', '·', '·', '·', '▓',' ',' ',' ',' ',' ',' ',' ',' ','▓','·','·','·','·','·','·','·','·' },
		{ '▓', '·', '▓', '·', '·', '▓', '▓', '▓', '·', '·', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '·', '·', '▓', '▓', '▓', '·', '·', '▓', '·', '▓'},
		{ '▓', '·', '▓', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '▓', '·', '▓' },
		{ '▓', '·', '▓', '▓', '▓', '·', '·', '▓', '·', '·', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '·', '·', '▓', '·', '·', '▓', '▓', '▓', '·', '▓' },
		{ '▓', '·', '·', '·', '·', '·', '·', '▓', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '·', '▓', '·', '·', '·', '·', '·', '·', '▓' },
		{ '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓', '▓' }*/
		/*{ W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
		{ W, O, O, O, O, O, O, W, O, O, O, O, O, O, O, O, O, O, O, O, O, O, W, O, O, O, O, O, O, W },
		{ W, O, W, W, W, O, O, W, O, O, W, W, W, W, W, W, W, W, W, W, O, O, W, O, O, W, W, W, O, W },
		{ W, O, W, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, W, O, W },
		{ W, O, W, O, O, W, W, W, O, O, W, W, ' ',' ',' ',' ',' ',' ', W, W, O, O, W, W, W, O, O, W, O, W },
		{ ' ',' ',O ,O, O, O, O, O, O, O, O, W,' ',' ',' ',' ',' ',' ',' ',' ',W,O,O,O,O,O,O,O,O }
		{ W, O, W, O, O, W, W, W, O, O, W, W, W, W, W, W, W, W, W, W, O, O, W, W, W, O, O, W, O, W},
		{ W, O, W, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, W, O, W },
		{ W, O, W, W, W, O, O, W, O, O, W, W, W, W, W, W, W, W, W, W, O, O, W, O, O, W, W, W, O, W },
		{ W, O, O, O, O, O, O, W, O, O, O, O, O, O, O, O, O, O, O, O, O, O, W, O, O, O, O, O, O, W },
		{ W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W }*/
	};
		 
	
	 //0123456789012345678901234567890
	//{
	//"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
	//"▓·······▓············▓·······▓",
	//"▓·▓▓▓···▓·▓▓▓▓▓▓▓▓▓▓·▓···▓▓▓·▓",
	//"▓·▓························▓·▓",
	//"▓·▓··▓▓▓··▓▓      ▓▓··▓▓▓··▓·▓",
	//" ·········▓········▓········· ",
	//"▓·▓··▓▓▓··▓▓▓▓▓▓▓▓▓▓··▓▓▓··▓·▓",
	//"▓·▓························▓·▓",
	//"▓·▓▓▓··▓··▓▓▓▓▓▓▓▓▓▓··▓··▓▓▓·▓",
	//"▓······▓··············▓······▓",
	//"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"
	//};

public:

	void printBoard();
	char getCell(Point p);
	void editCell(Point p, char ch);
};

#endif


