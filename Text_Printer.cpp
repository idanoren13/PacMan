#include "Text_Printer.h"

void Text_Printer::printObj(Point p, char c) {
	if (!silent)
		p.draw(c);
}

void Text_Printer::printMenu() {
	gotoxy(0, 0);
	setTextColor(Color::WHITE);
	clear_screen();
	printPacmanSign();
	cout << "Choose option from the following menu: " << endl
		<< " 1.\tStart a new game (with colors) " << endl
		<< " 2.\tStart a new game (without colors) " << endl
		<< " 3.\tChoose level " << endl
		<< " 4.\tInsert a screen name " << endl
		<< " 8.\tInstructions & keys " << endl
		<< " 9.\tExit" << endl;
}

void Text_Printer::printGamePause(int height) {
	setTextColor(Color::WHITE);
	gotoxy(0, height + 3);
	cout << "Game paused: press ESC to continue / press H to return the main menu";
	Sleep(650);
	cout << "\33[2K" << endl; // erase line from console
	Sleep(100);
}

void Text_Printer::printInstractions() {
	system("cls");
	cout << "\nWelcome to Pacman !" << endl << "Your goal is to move the pacman on the screen and eat the breadcrumbs." << endl
		<< "Each eaten breadcrumb equals a point to be earned." << endl
		<< "Once all breadcrumbs on screen are eaten you win the game :)\n" << endl
		<< "Keys for the game (make sure to use english keyboard!) :" << endl
		<< "LEFT -> a or A" << endl
		<< "RIGHT -> d or D" << endl
		<< "UP -> w or W" << endl
		<< "DOWN -> x or X" << endl
		<< "STAY -> s or S" << endl
		<< "ESC -> Pause" << endl
		<< "H after ESC -> return the main menu" << endl << endl
		<< "Press any key to return to the menu" << endl;
	_getch();
	system("cls");
}

void Text_Printer::printLevelMenu() {
	system("cls");
	gotoxy(0, 0);
	printPacmanSign();
	cout << "Choose game level [a/b/c] " << endl
		<< " a.\tBEST " << endl
		<< " b.\tGOOD " << endl
		<< " c.\tNOVICE " << endl;
}

void Text_Printer::printMsg(string s) {
	clear_screen();
	gotoxy(0, 0);
	setTextColor(Color(WHITE));
	s.append("\nPlease wait\n");
	cout << s;
	Sleep(3300);
	system("cls");
}

void Text_Printer::printPacmanSign() {
	cout << "" << endl
		<< "********************************************" << endl
		<< "    _____           __  __			      " << endl
		<< "   |  __ \\	   |  \\/  |		      " << endl
		<< "   | |__) |_ _  ___| \\  / | __ _ _ __      " << endl
		<< "   | ___ / _` |/ __| |\\/| |/ _` | '_ \\    " << endl
		<< "   | |  | (_| | (__| |  | | (_| | | | |     " << endl
		<< "   |_|   \\__,_|\\___|_|  |_|\\__,_|_| |_|   " << endl
		<< "                                            " << endl
		<< "********************************************" << endl;
}

void Text_Printer::printExit() {
	cout << endl
		<< "    .______                _____		   " << endl
		<< "   /       \\              /     \\		   " << endl
		<< "  /    O   /   _   _     / O O   \\     _   _   " << endl
		<< " |       ./   (_) (_)   |         |   (_) (_) " << endl
		<< " |       \\              | ~~~     | 	   " << endl
		<< " |        \\             |         |	   " << endl
		<< "  \\        /            |         |	   " << endl
		<< "   \\______/             |/vvvvvvv\\|      " << endl
		<< "\n             GOOD BYE     \n";
}

