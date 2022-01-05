#include "Regular_Mode.h"
#include "Load_Mode.h"
#include "Exceptions.h"

void check_input(int argc, char** argv, bool& isSaveMode, bool& saveOrSilent);
void play_pacman(int argc, char** argv);


void main(int argc, char** argv) {
	try { 
		play_pacman(argc, argv);
	}
	catch (ExceptionInvalidUserArgument& e) {
		e.Error();
	}
}


void play_pacman(int argc, char** argv) {
	bool isSaveMode, saveOrSilent;
	check_input(argc, argv, isSaveMode, saveOrSilent);

	if (isSaveMode) {
		Regular_Mode game(saveOrSilent);
		game.runGame();
	}
	else {
		Load_Mode game(saveOrSilent);
		game.runGame();
	}
}

//-save
//-save -silent (same as save) 
//-load
//-load -silent

/*
	if isSaveMode == true :=> regular game
	   isSaveMode == false :=> load game

	if saveOrSilent == true :=> save game || silent mode
*/

void check_input(int argc, char** argv, bool& isSaveMode, bool& saveOrSilent) {
	std::string str1, str2;

	if (argc == 1) {
		isSaveMode = true;
		saveOrSilent = false;
	}
	else if (argc == 2) {
		str1 = argv[1];
		if (str1.compare("-load") == 0) {
			isSaveMode = false;
			saveOrSilent = false;
		}
		else if (str1.compare("-save") == 0) {
			isSaveMode = true;
			saveOrSilent = true;
		}
		else
			throw ExceptionInvalidUserArgument(str1);
	}
	else if (argc == 3) {
		str1 = argv[1];
		str2 = argv[2];
		if (str1.compare("-load") == 0 && str2.compare("-silent") == 0) {
			isSaveMode = false;
			saveOrSilent = true;
		}
		else if (str1.compare("-save") == 0 && str2.compare("-silent") == 0) {
			isSaveMode = true;
			saveOrSilent = true;
		}
		else
			throw ExceptionInvalidUserArgument(str1 + " " + str2);
	}
	else
		throw ExceptionInvalidUserArgument();
}


