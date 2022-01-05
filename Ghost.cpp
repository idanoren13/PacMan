#include "Ghost.h"

//--------Getters and Setters---------------------------//

void Ghost::setGhost(Point p, Board& board) {
	prev_point = curr_point;
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
	curr_point.setPoint(p.getX(), p.getY());
	next_point = prev_point = curr_point;
}

//--------Methods------------------------------------//

void Ghost::move(Board& board) {
	switch (level) {
	case 'a':
		smartMove(board);
		break;
	case 'b':
		avgMove(board);
		break;
	case 'c':
		dumbMove(board);
		break;
	case 'd':
		controledMove(board);
	}
}

void Ghost::avgMove(Board& board) {
	if (move_cntr % 20 < 5)
		dumbMove(board);
	else {
		smartMove(board);
		move_cntr++;
	}
}


void Ghost::smartMove(Board& board) {
	int b_height = board.getHeight(), b_width = board.getWidth();
	Point near_cell, cell, pacmanPos = pacmanPoint;
	std::queue<Point> q;
	std::vector<std::vector<bool>> visitedPointArr(board.getHeight() + 1, std::vector<bool>(board.getWidth(), false));
	prev_point = curr_point;

	// Mark starting cell as visited
	q.push(pacmanPos);
	visitedPointArr[pacmanPos.getY()][pacmanPos.getX()] = true;
	int counter = 0;
	while (!q.empty()) {
		cell = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			near_cell = cell;
			near_cell.move(i);
			if (isNextToCurrPoint(pacmanPos)) {
				next_point = pacmanPos;
				printGhost(board);
				return;
			}
			if (isNextToCurrPoint(near_cell) && board.getCell(near_cell) != (unsigned char)WALL) {
				next_point = near_cell;
				printGhost(board);
				return;
			}

			else if (board.isPointValid(near_cell) && board.getCell(near_cell) != (unsigned char)WALL && visitedPointArr[near_cell.getY()][near_cell.getX()] == false) {
				q.push(near_cell);
				visitedPointArr[near_cell.getY()][near_cell.getX()] = true;
			}
		}
		counter++;
	}
	q.empty();
}

void Ghost::dumbMove(Board& board) {
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
	printGhost(board);
}

void Ghost::printGhost(Board& board) {
	setTextColor(Color::LIGHTGREY);
	creature_printer.printObj(curr_point, board.getCell(curr_point));
	curr_point = next_point;
	printCreature();
}

bool Ghost::isNextToCurrPoint(Point _p) {
	return (((std::abs(_p.getX() - curr_point.getX()) <= 1) && (_p.getY() == curr_point.getY())) ||
		((std::abs(_p.getY() - curr_point.getY()) <= 1) && (_p.getX() == curr_point.getX())));
}

bool Ghost::isValidMove(Board& board, Point point) {
	return (isEndBoard(board.getHeight(), board.getWidth()) || board.getCell(point) == (unsigned char)WALL);
}
