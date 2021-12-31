#pragma once
#include "io_utils.h"
#include "Ghost.h"
#include "Creature.h"
#include <fstream>
#include <iostream>

class File_handler
{

private:
	std::queue<std::string> q;

	std::ofstream output;
	std::ifstream input;
	bool is_open_out = false;
	bool is_open_in = false;

	enum class char_format{u,d,l,r,s,k};

	std::string formatLine(const Creature& pacman,const Creature*& ghost,const Creature& fruit);


public:
	File_handler();
	~File_handler();
	void init_output(std::string filename) { output.open(filename, ios::out); is_open_out = true; }
	void write2File(std::string filename);

	void init_input(std::string filename) { input.open(filename, ios::in); is_open_in = true; }
	void readFromFile(std::string filename);

	void push2Queue(std::string str);
	std::string readFromQueue();
};

