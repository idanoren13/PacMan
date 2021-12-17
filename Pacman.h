#ifndef PACMAN_H_
#define PACMAN_H_

#include "Point.h"
#include "Color.h"
#include "Board.h"
#include "Creature.h"

class Pacman : public Creature {
	int score;
	int fruitScore;
	int life;

	public:
		//--------Constructors--------//
		Pacman() : Creature(Point(2,9), YELLOW, PACMAN, STAY), score(0), fruitScore(0), life(3) {}
		Pacman(Point _p): Creature(_p, YELLOW, PACMAN, STAY), score(0), fruitScore(0), life(3) {}
		
		//-----Setters & Getters------//
		void setPacman(Point p);
		void setLife(int _life) { life = _life; }
		void setScore(int _score) { score += _score; }
		void resetScore() { score = 0; }
		void setFruitScore(int _fruitScore) { fruitScore += _fruitScore; }

		int getLife() { return life; }
		int getScore() { return score; }
		int getFruitScore() { return fruitScore; }

		//----------Methods-----------//
		void move(Board &board);
		void isEndBoard(int height, int width);
};

#endif 


