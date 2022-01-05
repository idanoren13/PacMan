#pragma once
class Exceptions {};

// 2 3 =>how many variables
// 2 => incorrect input
class ExceptionInvalidUserArgument : public Exceptions {
public:
	void Error() {
		cout << "Error: Invalid Argument" << endl;
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

