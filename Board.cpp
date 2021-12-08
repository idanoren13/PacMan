#include "Board.h"

void Board::initBoard() {
	unsigned char _board[HEIGHT][WIDTH] =
	{
		{' '},
		{' ', wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, ' ', ' ', wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa },
		{' ', wa, wa, br, br, br, br, br, br, br, br, wa, wa, br, br, br, br, br, br, wa, wa, ' ', ' ', wa, wa, br, br, br, br, br, br, wa, wa, br, br, br, br, br, br, br, br, wa, wa },
		{' ', wa, wa, br, br, wa, wa, wa, wa, br, br, wa, wa, br, br, wa, wa, br, br, wa, wa, ' ', ' ', wa, wa, br, br, wa, wa, br, br, wa, wa, br, br, wa, wa, wa, wa, br, br, wa, wa },
		{' ', wa, wa, br, br, wa, wa, wa, wa, br, br, wa, wa, br, br, wa, wa, br, br, br, br, br, br, br, br, br, br, wa, wa, br, br, wa, wa, br, br, wa, wa, wa, wa, br, br, wa, wa },
		{' ', wa, wa, br, br, wa, wa, br, br, br, br, wa, wa, br, br, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, br, br, wa, wa, br, br, br, br, wa, wa, br, br, wa, wa },
		{' ', wa, wa, br, br, wa, wa, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, wa, wa, br, br, wa, wa },
		{' ', wa, wa, br, br, wa, wa, br, br, br, br, wa, wa, br, br, br, wa, wa, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', wa, wa, br, br, br, wa, wa, br, br, br, br, wa, wa, br, br, wa, wa },
		{' ', wa, wa, br, br, br, br, br, br, br, wa, wa, wa, wa, br, br, wa, wa, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', wa, wa, br, br, wa, wa, wa, wa, br, br, br, br, br, br, br, wa, wa },
		{' ', ' ', ' ', br, br, br, br, br, br, br, br, br, br, br, br, br, wa, wa, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', wa, wa, br, br, br, br, br, br, br, br, br, br, br, br, br, ' ', ' ' },
		{' ', wa, wa, br, br, wa, wa, br, br, br, wa, wa, wa, wa, br, br, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, br, br, wa, wa, wa, wa, br, br, br, wa, wa, br, br, wa, wa },
		{' ', wa, wa, br, br, wa, wa, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, wa, wa, br, br, wa, wa },
		{' ', wa, wa, br, br, wa, wa, br, br, br, br, wa, wa, br, br, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, br, br, wa, wa, br, br, br, br, wa, wa, br, br, wa, wa },
		{' ', wa, wa, br, br, wa, wa, wa, wa, br, br, wa, wa, br, br, wa, wa, ' ', ' ', 'P','a','c','M','a','n',' ',' ', wa, wa, br, br, wa, wa, br, br, wa, wa, wa, wa, br, br, wa, wa },
		{' ', wa, wa, br, br, wa, wa, wa, wa, br, br, wa, wa, br, br, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, br, br, wa, wa, br, br, wa, wa, wa, wa, br, br, wa, wa },
		{' ', wa, wa, br, br, br, br, br, br, br, br, wa, wa, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, wa, wa, br, br, br, br, br, br, br, br, wa, wa },
		{' ', wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, ' ', ' ', wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa }
	};
	for (int i = 0; i < HEIGHT; i++)
		for (int j = 0; j < WIDTH; j++)
			board[i][j] = _board[i][j];
}


void Board::printBoard(bool black_and_white) {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (board[i][j] == (unsigned char)WALL) {
				if(!black_and_white)
					setTextColor(Color::LIGHTCYAN);
				cout << board[i][j];
			}
			else if (board[i][j] == (unsigned char)BREAD) {
				if (!black_and_white)
					setTextColor(Color::LIGHTGREY);
				cout << board[i][j];
			}
			else {
				setTextColor(Color::WHITE);
				cout << board[i][j];
			}
		}
		cout << endl;
	}
	setTextColor(Color::WHITE);
}

char Board::getCell(Point p) {
	return board[p.getY()][p.getX()];
}

void Board::editCell(Point p, char ch) {
	board[p.getY()][p.getX()] = ch;
}

void Board::printData(int score, int life) {
	setTextColor(Color::WHITE);
	gotoxy(0, HEIGHT + 1);
	cout << "Current Score   : " << score << endl;
	cout << "Remaining Lives : " << life << endl;

}



//Board::Board() {
//
//	board = {
//		{' '},
//		{ ' ', wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, ' ', ' ', wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa},
//		{ ' ', wa, br, br, br, br, br, br, br, wa, br, br, br, br, br, br, br, br, br, br, br, br, br, br, wa, br, br, br, br, br, br, br, wa },
//		{ ' ', wa, br, br, wa, wa, wa, br, br, wa, br, br, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, br, br, wa, br, br, wa, wa, wa, br, br, wa },
//		{ ' ', wa, br, br, wa, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, wa, br, br, wa },
//		{ ' ', wa, br, br, wa, br, br, wa, wa, wa, br, br, wa, wa, ' ', ' ', ' ', ' ', ' ', ' ',  wa, wa, br, br, wa, wa, wa, br, br, wa, br, br, wa },
//		{ ' ', ' ', br, br ,br, br, br, br, br, br, br, br, wa, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', wa, br, br, br, br, br, br, br, br, br, br,' ',' '},
//		{ ' ', wa, br, br, wa, br, br, wa, wa, wa, br, br, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, br, br, wa, wa, wa, br, br, wa, br, br, wa},
//		{ ' ', wa, br, br, wa, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, br, wa, br, br, wa },
//		{ ' ', wa, br, br, wa, wa, wa, br, br, wa, br, br, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, br, br, wa, br, br, wa, wa, wa, br, br, wa },
//		{ ' ', wa, br, br, br, br, br, br, br, wa, br, br, br, br, br, br, br, br, br, br, br, br, br, br, wa, br, br, br, br, br, br, br, wa },
//		{ ' ', wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, ' ', ' ', wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa, wa }
//
//	};
//}
