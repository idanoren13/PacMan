#include "File_handler.h"


//** ** ** 
//pp pp gg gg gg gg gg gg ff ff s
std::string File_handler::formatLine(const Creature& pacman, const std::vector<Ghost>& ghosts, const Fruit& fruit, const bool fruitActive){
	std::string str;
	str.append(std::to_string(pacman.getCurrPoint().getX()));
	str.push_back(' ');
	str.append(std::to_string(pacman.getCurrPoint().getY()));
	for (const Ghost& _ghost : ghosts) {
		str.push_back(' ');
		str.append(std::to_string(_ghost.getCurrPoint().getX()));
		str.push_back(' ');
		str.append(std::to_string(_ghost.getCurrPoint().getY()));
	}
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
	close_input(filename);
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
	close_output(screenName);
}

void File_handler::getResult(int*& a, std::string fileName) {
	std::string name = (fileName.substr(0, fileName.find(".screen"))).append(".result");
	result.flush();
	result.open(name, ios::out);
	if (result.is_open()) {

		std::string str;
		std::getline(result, str);
		std::stringstream ss;
		ss << (str.substr(35, str.size() - 8));
		ss >> a[0];
		std::getline(result, str);
		ss << (str.substr(20, str.size() - 8));
		ss >> a[1];
		result.close();
	}
}

void File_handler::close_output(std::string filename) {
	output.close();
	result.close();
}




