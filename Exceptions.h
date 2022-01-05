#pragma once
class Exceptions {};

class ExceptionInvalidUserArgument : public Exceptions {
	std::string str = "";

public:
	ExceptionInvalidUserArgument() {}
 	ExceptionInvalidUserArgument(std::string _s) : str(": " + _s) {}

	void Error() {
		cout << "Error: Invalid Argument " << str << endl;
	}
};

class ExceptionNoScreenWasFound : public Exceptions {
public:
	void Error() {
		cout << "Error: No Screen" << endl;
	}
};

//class ExceptionInvalidArgv_1 : ExceptionInvalidUserArgument {
//public:
//	virtual const char* Error(){
//		return "Error: Invalid Argv[1]";
//	}
//};
//
//class ExceptionInvalidArgv_2 : ExceptionInvalidUserArgument {
//public:
//	virtual const char* Error() {
//		return "Error: Invalid Argv[1] or Argv[2]";
//	}
//};
//
//class ExceptionInvalidArg : ExceptionInvalidUserArgument {
//public:
//	virtual const char* Error() {
//		return "Error: Invalid User  Argouments";
//	}
//};

