#include "Regular_Mode.h"
#include "Load_Mode.h"
#include "Exceptions.h"

void checkInput(bool& isSaveMode, bool& saveOrSilent, int argc, char argv[2][25]);

void main(int argc, char** argv) {

	/*
		if isSaveMode == true :=> regular game
		   isSaveMode == false :=> load game

		if saveOrSilent == true :=> save game || silent mode
	*/

	bool isSaveMode, saveOrSilent;
	//try { checkInput(isSaveMode, saveOrSilent, argc, argv); }
	char argv1[2][25] = { "pacman.exe","-lo" };


	 checkInput(isSaveMode, saveOrSilent, 2, argv1); 
	

	//cout << "isSaveMode: " << isSaveMode << endl
	//	<< "saveOrSilent: " << saveOrSilent << endl;

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

void checkInput(bool& isSaveMode, bool& saveOrSilent, int argc, char argv[2][25]) {
	try {
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
			throw ExceptionInvalidArgv_1();
	}
	else if (argc == 3) {
		str1 = argv[1];
		str2 = argv[2];
		if (str1.compare("-load") == 0 && str2.compare("-silent") == 0) {
			isSaveMode = false;
			saveOrSilent = true;
		}
		else
			throw ExceptionInvalidArgv_2();
	}
	else
		throw ExceptionInvalidArg();
	}
	catch (ExceptionInvalidUserArgoument& e) {
	cout << e.Error();
	}
}


