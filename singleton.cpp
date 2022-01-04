#include "singleton.h"

//template <class T>
//void singleton::print(const T& t,Board& board){
//	if (!silent) {
//		switch (typeid(t))
//		{
//			case typeid(Pacman) :
//				(Pacman)(t).Pacman::printPacman(board);
//				break;
//				
//			case typeid(Ghost) :
//				(Ghost)(t)Ghost::printGhost(board);
//			break;
//
//			case typeid(Fruit) :
//				(Fruit)(t)Fruit::printFruit(board);
//				break;
//					
//		default:
//			std::cout << t;
//			break;
//		}
//	}
//}

void singleton::printObj(Point _p, Color color, char ch) {
	if (!silent) {
		setTextColor(color);
		_p.draw(ch);
	}
}


//void singleton::printPacman(Pacman pacman) {
//	(pacman.getCurrPoint()).draw(' ');
//	board.editCell(curr_point, ' ');
//	curr_point = next_point;
//	printCreature();
//}