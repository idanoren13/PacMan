#pragma once
class Exceptions {};

// 2 3 =>how many variables
// 2 => incorrect input
class ExceptionInvalidUserArgoument : public Exceptions {
public:
	virtual const char* Error() = 0;
};

class ExceptionInvalidArgv_1 : ExceptionInvalidUserArgoument {
	virtual const char* Error(){
		return "Error: Invalid Argv[1]";
	}
};

class ExceptionInvalidArgv_2 : ExceptionInvalidUserArgoument {
	virtual const char* Error() {
		return "Error: Invalid Argv[1] or Argv[2]";
	}
};

class ExceptionInvalidArg : ExceptionInvalidUserArgoument {
	virtual const char* Error() {
		return "Error: Invalid User  Argouments";
	}
};

