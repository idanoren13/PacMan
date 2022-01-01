#include "Board.h"

// //--------Constructors--------//

// Board::Board() {
// 	num_of_ghosts = 0;
// 	num_of_bread_crumbs = 0;
// 	height = width = 0;
// }

//-----Setters & Getters------//

unsigned char Board::getCell(Point p) {
	return board[p.getY()][p.getX()];
}

void Board::editCell(Point p, char ch) {
	board[p.getY()][p.getX()] = ch;
}

void Board::resetBoard() {
num_of_bread_crumbs = num_of_ghosts = 0; 
validScreen = true;
errMsg = "";
}


//----------Methods-----------//

Point Board::getRandomPoint() {
	Point res;
	res.setPoint(rand() % (width - 3), rand() % (height - 3));

	while (getCell(res) == (Shape)WALL || getCell(res) == (Shape)PACMAN)
		res.setPoint(rand() % (width - 3), rand() % (height - 3));

	return res;
}

void Board::initBoard(const char* filename)
{
	int col = 0, row = 0, countChars = 0;
	char read;
	resetBoard();

	ifstream in_file(filename, ios::ate);
	if (!(in_file.is_open())) {
		validScreen = false;
		errMsg = "Screen does not exist";
		return;
	}

	int fileSize = in_file.tellg();
	in_file.seekg(0, in_file.beg);

	while ((countChars <= fileSize) && (row < MAX_ROWS) && (col < MAX_COLS))
	{
		if (!validScreen)
			return;
		read = in_file.get();
		handleRead(read, row, col, countChars);
		col++;
		countChars++;
	}

	height = row - 1;
	initiateLegend();
	if (!initPacman) {
		validScreen = false;
		errMsg = "Invalid screen, missing Pacman position";
	}
	in_file.close();
}

void Board::initiateLegend() {
	if (!initLegend) {
		validScreen = false;
		errMsg = "Invalid screen, missing Legend position";
	}

	else {
	int row = legendPos.getY();
	int col = legendPos.getX();

	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 20; i++) 
			board[row + j][col + i] = ' ';
	}
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
		if (initPacman) {
			validScreen = false;
			errMsg = "Invalid screen, cannot initiate more then 1 Pacman";
			return;
		}
		pacmanPos.setPoint(col, row);
		board[row][col] = ' ';
		initPacman = true;
		break;
	case '$':
		if (num_of_ghosts > 4) {
			validScreen = false;
			errMsg = "Invalid screen, cannot initiate more then 4 ghosts";
			return;
		}
		ghostsPos[num_of_ghosts].setPoint(col, row);
		num_of_ghosts++;
		board[row][col] = ' ';
		break;
	case '&':
		if (initLegend){
			validScreen = false;
			errMsg = "Invalid screen, cannot initiate more then 1 Legend";
			return;
		}
		legendPos.setPoint(col, row);
		board[row][col] = ' ';
		initLegend = true;
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
		validScreen = false;
		errMsg = "Invalid screen, file contain invalid chars";
		break;
	}
}

void Board::printBoard(bool black_and_white) {
	gotoxy(0, 0);
	setTextColor(Color::WHITE);
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
	gotoxy(legendPos.getX(), legendPos.getY() + 1);
	cout << "Remaining Lives: " << life << endl;
}