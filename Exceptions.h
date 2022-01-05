#pragma once
class Exceptions {};

class ExceptionInvalidUserArgument : public Exceptions {
	std::string str = "";

public:
	ExceptionInvalidUserArgument() {}
 	ExceptionInvalidUserArgument(std::string _s) : str(": " + _s) {}

	void Error() {
		clear_screen();
		cout << "Error: Invalid Argument " << str << endl << endl
			<< "To run pacman.exe use one of the following arguments: " << endl
			<< "(1) no arguments : run program without saving" << endl
			<< "(2) -save : run program and save results" << endl
			<< "(3) -load : run last game played" << endl
			<< "(4) -load -silent : tests" << endl;
	}
};

class ExceptionNoScreenWasFound : public Exceptions {
public:
	void Error() {
		cout << "Error: No Screen" << endl;
	}
};
