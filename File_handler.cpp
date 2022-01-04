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

void File_handler::getResult(int*& a, std::string fileName) {
	std::string name = (fileName.substr(0, fileName.find(".screen"))).append(".result");
	//name = "pacman_01.result";
	read_result.open(name);
	if (read_result.is_open()) {

		std::string str;
		std::getline(read_result, str);
		std::stringstream ss;
		ss << (str.substr(18, str.size() - 6));
		ss >> a[0];
		std::getline(read_result, str);
		ss.str("");
		ss << (str.substr(5, str.size() - 7));
		ss >> a[1];
		read_result.close();
	}
}


