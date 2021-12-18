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

void Ghost::move(Board& board, Creature& pacman, char level) {
	switch (level) {
	case 'a':
		smartMove(board, pacman);
		break;
	case 'b':
		avgMove(board);
		break;
	case 'c':
		dumbMove(board);
		break;

	}

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
	setTextColor(Color::LIGHTGREY);
	curr_point.draw(board.getCell(curr_point));
	curr_point = next_point;
	printCreature();
}

bool Ghost::isEndBoard(int height, int width) {
	return (next_point.getX() > width - 1 || next_point.getX() < 0 || next_point.getY() > height - 1 || next_point.getY() < 0);
}


void Ghost::smartMove(Board& board, Creature& pacman) {
	Point near_cell, cell, ghostPos = this->getCurrPoint(), pacmanPos = pacman.getCurrPoint();
	std::queue<Point> q;
	std::vector<std::vector<bool>> visitedPointArr(board.getHeight() + 1, std::vector<bool>(board.getWidth(), false));

	// Mark starting cell as visited
	q.push(pacmanPos);
	visitedPointArr[pacmanPos.getY()][pacmanPos.getX()] = true;

	while (!q.empty()) {
		cell = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			near_cell = cell;
			near_cell.move(i);

			if (near_cell.isSamePoint(ghostPos))
				return cell; //need to set it to ghost vector instead

			else if (isValidMove(board, near_cell) && visitedPointArr[near_cell.getY()][pacmanPos.getX()] == false) {
				q.push(near_cell);
				visitedPointArr[near_cell.getY()][pacmanPos.getX()] = true;
			}
		}
	}
}

bool Ghost::isValidMove(Board& board, Point point) {
	return isEndBoard(board.getHeight(), board.getWidth(), point) || board.getCell(point) == (unsigned char)WALL;
}

bool Ghost::isEndBoard(int height, int width, Point point) {
	return (point.getX() > width - 1 || point.getX() < 0 || point.getY() > height - 1 || point.getY() < 0);
}