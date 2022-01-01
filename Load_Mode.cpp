#include "Load_Mode.h"

void Load_Mode::runGame(bool silent) {
	if (silent)
		runSilentMode();
	else
		run();
}

void Load_Mode::run() {
	
}

void Load_Mode::runScreen(bool& didILose, bool& continue_game) {

}

void Load_Mode::runSilentMode() {
	
}
