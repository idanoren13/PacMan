#include "Pacman.h"

//--------Constructors--------//

//-----Setters & Getters------//

void Pacman::setPacman(Point p) {
	curr_point.draw(' ');
	curr_point.setPoint(p.getX(), p.getY());
	prev_point = curr_point;
	next_point = curr_point;
	v = STAY;
	printCreature();
}

//----------Methods-----------//

void Pacman::move(Board& board) {
	if (v != STAY) {
		prev_point = curr_point;
		next_point = curr_point;
		next_point.move(v);
		isEndBoard(board.getHeight(), board.getWidth());
		unsigned char readCurrVal = board.getCell(curr_point);
		unsigned char readNextVal = board.getCell(next_point);
		if (readCurrVal == (unsigned char)BREAD) {
			score++;
		}
		if (readNextVal == (unsigned char)WALL) {
			v = STAY;
			next_point = curr_point;
		}
		curr_point.draw(' ');
		board.editCell(curr_point, ' ');
		curr_point = next_point;
		printCreature();
	}
}

void Pacman::isEndBoard(int height, int width) {
	if (next_point.getX() > width - 1)
		next_point.setPoint(0, next_point.getY());
	else if (next_point.getX() < 0)
		next_point.setPoint(width - 1, next_point.getY());
	else if (next_point.getY() > height - 1)
		next_point.setPoint(next_point.getX(), 0);
	else if (next_point.getY() < 0)
		next_point.setPoint(next_point.getX(), height - 1);
}