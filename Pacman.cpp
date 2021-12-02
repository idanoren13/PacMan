#include "Pacman.h"

//--------Constructors---------------------------------//

//--------Getters and Setters---------------------------//
void Pacman::setPacman(Point p) {
	this->getCreature().draw(' ');
	getCreature().setPoint(p.getX(), p.getY());
	prev_point = curr_point;
	next_point = curr_point;
	v = STAY;
	printPacman();
}

//--------Methods------------------------------------//

void Pacman::movePacman(Board& board) {
	if (v != STAY) {
		prev_point = curr_point;
		next_point = curr_point;
		next_point.move(v);
		isEndBoard();
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
		printPacman();
	}
}

void Pacman::printPacman() {
	setTextColor(color);
	curr_point.draw(shape);
}

void Pacman::isEndBoard() {
	if (next_point.getX() == WIDTH - 1)
		next_point.setPoint(1, next_point.getY());
	else if(next_point.getX() < 1)
		next_point.setPoint(WIDTH-2, next_point.getY());
	else if (next_point.getY() > HEIGHT - 1)
		next_point.setPoint(next_point.getX(),1);
	else if (next_point.getY() < 1)
		next_point.setPoint(next_point.getX(), HEIGHT - 1);
}