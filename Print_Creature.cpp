#include "Print_Creature.h"


void Print_Creature::printObj(Point _p, char ch) {
	if (!silent) {
		_p.draw(ch);
	}
}