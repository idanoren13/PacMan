#include "File_handler.h"

char File_handler::directionLetter(const Move_Vector& _v) {
	char ch;
	switch (_v)
	{
	case UP:
		ch = 'u';
		break;
	case DOWN:
		ch = 'd';
		break;
	case LEFT:
		ch = 'l';
		break;
	case RIGHT:
		ch = 'r';
		break;
	case STAY:
		ch = 's';
		break;
	default:
		ch = 0;
		break;
	}
	return ch;
}
//** ** ** 
//pp pp gg gg gg gg gg gg ff ff s
std::string File_handler::formatLine(const Creature& pacman, const std::vector<Ghost>& ghosts, const Fruit& fruit, const bool fruitActive){
	std::string str;
	str.append(std::to_string(pacman.getCurrPoint().getX()));
	str.push_back(' ');
	str.append(std::to_string(pacman.getCurrPoint().getY()));
	for (const Ghost& _ghost : ghosts)
		str.push_back(' ');
		str.append(std::to_string(_ghost.getCurrPoint().getX()));
		str.push_back(' ');
		str.append(std::to_string(_ghost.getCurrPoint().getY()));
	if (fruitActive) {
		str.push_back(' ');
		str.append(std::to_string(fruit.getCurrPoint().getX()));
		str.push_back(' ');
		str.append(std::to_string(fruit.getCurrPoint().getY()));
		str.push_back(' ');
		str.push_back(fruit.getShape());
	}
	str.push_back('\n');
	return str;
}

std::string File_handler::readFromQueue() {
	std::string s = "";
	if (q.size() > 0) {
		s = q.front();
		q.pop();
	}
	return s;
}

void File_handler::readFromFile(std::string filename) {
	std::string str;

	init_input((filename.substr(0, filename.find(".screen"))).append(".steps"));

	while (!input.eof()) {
		std::getline(input, str);
		q.push(str);
	}
}


void File_handler::makeEmptyQueue() {
	while (!q.empty())
		q.pop();
}

void File_handler::init_output(std::string filename) {
	output.open(filename + ".steps", ios::out);
	result.open(filename + ".result", ios::out);

	is_open_out = true;
}

void File_handler::write2Files(std::string screenName, bool didILose, int point_of_time, int score) {
	init_output(screenName.substr(0, screenName.find(".screen")));
	while (q.size() > 0) {
		output << q.front();
		q.pop();
	}
	if (!didILose)
		result << "Pacman finished the screen at the " << point_of_time << "th move";
	else
		result << "Pacman died at the " << point_of_time << "th move";
	result << endl << "With " << score <<" points";
}



//TODO: finish if we have time
//bool File_handler::checkFormatVadility(std::string str) {
//	/*Point fp;
//	char ch;
//	std::string temp;
//	std::string set = "lurds";
//
//	if (str.size() == 0 || str.size() > 13)
//		return false;
//	str >> temp;
//	if (temp.size() - 1 != num_of_ghost)
//		return false;
//	for (ch; ch != 0;ch=getc(temp)) {
//		if (!set.find(ch))
//			return false;
//	}
//	if (str >> temp) {
//		;
//	}*/
//	;
//}

