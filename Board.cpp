#include "Board.h"

//--------Constructors--------//

Board::Board() {
	num_of_ghosts = 0;
	num_of_bread_crumbs = 0;
}

//-----Setters & Getters------//

char Board::getCell(Point p) {
	return board[p.getY()][p.getX()];
}

void Board::editCell(Point p, char ch) {
	board[p.getY()][p.getX()] = ch;
}


//----------Methods-----------//

void Board::initBoard(const char* filename) 
{
	// TODO: filename input check

	int col = 0, row = 0, countChars = 0;
	char read;

	ifstream in_file(filename, ios::ate);
	if (!(in_file.is_open())) /*handle case*/;
	int fileSize = in_file.tellg();
	in_file.seekg(0, in_file.beg);
	
	while ((countChars <= fileSize) && (row <= MAX_ROWS) && (col <= MAX_COLS))
	{
		read = in_file.get();
		handleRead(read, row, col, countChars);
		col++;
		countChars++;
	}

	height = row;
	initLegend();
	in_file.close();
}

void Board::initLegend() {

	int row = legendPos.getY();
	int col = legendPos.getX();

	/*if (row >= height - 1)
		height += 2;
	if (col == width - 1)
		width += 19;*/

	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 20; i++) 
			board[row + j][col + i] = ' ';
}

void Board::handleRead(const char read, int& row, int& col, int& countChars) {
	switch (read)
	{
	case '\n':
		if (row == 0)
			width = col;	  // first line sets the board's width	
		while (col < width) { // handle case where current row length < first row
			board[row][col] = ' ';
			col++;
		}
		row++;
		col = -1;
		countChars++;		  // '\n' weight as 2 chars when read from file
		break;
	case '@':
		pacmanPos.setPoint(col, row);
		board[row][col] = ' ';
		break;
	case '$':
		ghostsPos[num_of_ghosts].setPoint(col, row);
		num_of_ghosts++;
		board[row][col] = ' ';
		break;
	case '&':
		legendPos.setPoint(col, row);
		board[row][col] = ' ';
		break;
	case '%':
		board[row][col] = ' ';
		break;
	case '#':
		board[row][col] = WALL;
		break;
	case ' ':
		board[row][col] = BREAD;
		num_of_bread_crumbs++;
		break;
	default:
		board[row][col] = ' ';
		break;
	}
}

void Board::printBoard(bool black_and_white) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (board[i][j] == (unsigned char)WALL) {
				if (!black_and_white)
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

void Board::printData(int score, int life) {
	setTextColor(Color::WHITE);
	gotoxy(legendPos.getX(), legendPos.getY());
	cout << "Current Score  : " << score << endl;
	cout << "Remaining Lives: " << life << endl;
}

void Board::initDefaultBoard() {
	unsigned char _board[17][43] =
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
	for (int i = 0; i < 17; i++)
		for (int j = 0; j < 43; j++)
			board[i][j] = _board[i][j];
}

