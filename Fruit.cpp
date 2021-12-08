#include "Fruit.h"

//--------Getters and Setters---------------------------//

void Fruit::setFruit(Point p, Board& board) {
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
	//curr_point.setPoint(p.getX(), p.getY());
	next_point = prev_point = curr_point = p;
}

//--------Methods------------------------------------//

void Fruit::move(Board& board) {
	prev_point = curr_point;
	if (move_cntr == 20)
		move_cntr = 0;
	next_point.move(v);

	unsigned char readVal = board.getCell(next_point);
	while (isEndBoard() || readVal == (unsigned char)WALL)
	{
		if (move_cntr % 5 == 0)
			setVector((Move_Vector)(v - 1));
		//v = (Move_Vector)(v - 1);
		else
			setVector((Move_Vector)(v + 1));
		//v = (Move_Vector)(v + 1);

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

bool Fruit::isEndBoard() {
	return (next_point.getX() > WIDTH - 2 || next_point.getX() < 1 || next_point.getY() > HEIGHT - 1 || next_point.getY() < 1);
}