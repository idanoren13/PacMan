#pragma once
#include "io_utils.h"
#include "Creature.h"
#include <string>
#include <queue>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "Ghost.h"
#include "Fruit.h"


class File_handler
{

private:
	std::queue<std::string> q;
	std::ofstream output;
	std::fstream result;
	std::ifstream input;
	bool is_open_out = false;
	bool is_open_in = false;
	int num_of_ghost;
	bool isNameValid();
	bool checkFormatVadility(std::string str);

public:
	void setNumOfGhost(int n) { num_of_ghost = n; }
	void makeEmptyQueue();

	//load
	std::string readFromQueue();
	void init_input(std::string filename) { input.open(filename, ios::in); is_open_in = true; }
	void readFromFile(std::string filename);

	//save
	void init_output(std::string filename);
	std::string formatLine(const Creature& pacman, const std::vector<Ghost>& ghosts, const Fruit& fruit, const bool fruitActive);
	void push2Queue(std::string str) { q.push(str); }
	void write2Files(std::string screenName, bool didILose, int point_of_time, int score); //saves .steps and .result files

	void getResult(int*& a, std::string fileName);

};

