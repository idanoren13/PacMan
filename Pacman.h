#ifndef PACMAN_H_
#define PACMAN_H_

#include "Point.h"
#include "Color.h"
#include "Board.h"
#include "Creature.h"

class Pacman : public Creature {
	int score;
	int life;

	public:
		//--------Constructors--------//
		Pacman(Point _p): Creature(_p, YELLOW, PACMAN, STAY), score(0), life(3) {}
		
		//-----Setters & Getters------//
		void setPacman(Point p);
		void setLife(int _life) { life = _life; }

		int getLife() { return life; }
		int getScore() { return score; }

		//----------Methods-----------//
		void movePacman(Board &board);
};

#endif 


