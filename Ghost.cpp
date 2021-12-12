#include "Ghost.h"

//--------Getters and Setters---------------------------//

void Ghost::setGhost(Point p, Board& board) {
	prev_point = curr_point;
	unsigned char readVal = board.getCell(curr_point);
	switch (readVal) {
	case (unsigned char)BREAD:
		setTextColor(Color::LIGHTGREY);
		curr_point.draw((unsigned char)BREAD);
		break;
	default:
		curr_point.draw(' ');
		break;
	}
	curr_point.setPoint(p.getX(), p.getY());
	next_point = curr_point;
}

//--------Methods------------------------------------//

void Ghost::move(Board& board) {
	prev_point = next_point = curr_point;
	if (move_cntr == 20) {
		next_point.move();
		move_cntr = 0;
	}
	else
		next_point.move(v);

	unsigned char readVal = board.getCell(next_point);
	while (isEndBoard(board.getHeight(), board.getWidth()) || readVal == (unsigned char)WALL || readVal == (unsigned char)GHOST)
	 {
		if (move_cntr % 5 == 0)
			setVector((Move_Vector)(v - 1));
		else
			setVector((Move_Vector)(v + 1));

		 if (v >= STAY)
			 v = UP;
		 if (v < UP)
			 v = DOWN;
		 next_point = curr_point;
		 next_point.move(v);
		 readVal = board.getCell(next_point);
	 }

	move_cntr++;
	setTextColor(Color::LIGHTGREY);
	curr_point.draw(board.getCell(curr_point));
	curr_point = next_point;
	printCreature();
}

bool Ghost::isEndBoard(int height, int width) {
	return (next_point.getX() > width - 1 || next_point.getX() < 0 || next_point.getY() > height - 1 || next_point.getY() < 0);
}