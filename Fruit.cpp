#include "Fruit.h"

//--------Getters and Setters---------------------------//

void Fruit::setFruit(Point p, Board& board) {
	unsigned char readVal = board.getCell(curr_point);
	switch (readVal) {
	case (unsigned char)BREAD:
		setTextColor(Color::LIGHTGREY);
		creature_printer.printObj(curr_point, (unsigned char)BREAD);
		break;
	default:
		creature_printer.printObj(curr_point, ' ');
		break;
	}
	next_point = prev_point = curr_point = p;
}

//--------Methods------------------------------------//

void Fruit::move(Board& board) {
	int overrun = 0;
	prev_point = next_point = curr_point;
	if (move_cntr == 20) {
		next_point.move();
		move_cntr = 0;
	}
	else
		next_point.move(v);

	unsigned char readVal = board.getCell(next_point);
	while (isEndBoard(board.getHeight(), board.getWidth()) || readVal == (unsigned char)WALL)
	{
		if (move_cntr % 5 == 0){
			setVector((Move_Vector)(v - 1));
			move_cntr = 1;
		}
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


