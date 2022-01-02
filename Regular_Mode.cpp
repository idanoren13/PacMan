#include "Regular_Mode.h"

void Regular_Mode::runGame(bool _save_mode) {
	char choice;
	save_mode = _save_mode;

	while (true)
	{
		choice = menu();

		switch (choice) {
		case '1':
			black_and_white = false;
			run();
			break;
		case '2':
			black_and_white = true;
			run();
			break;
		case '9':
			printExit();
			return;
		}
		fileName = "";
		screenNames.clear();
	}
}

void Regular_Mode::run() {
	bool didILose = false;
	bool continue_game = true;

	readScreens();

	if (continue_game)
	{
		for (string& screen : screenNames)
		{
			resetGame(screen);
			if (!board.isValidScreen())
				return;

			runScreen(didILose, continue_game);
			if (!continue_game)
				break;

			if (save_mode)
				my_stream.write2Files(screen, didILose, point_of_time);

			if (!didILose)
				winGame();
			else {
				gameOver();
				break;
			}
		}
		if (!didILose && continue_game)
			printMsg("You won the last screen, congrats !\n");
	}
}

void Regular_Mode::runScreen(bool& didILose, bool& continue_game)
{
	int slowCreature = 0;
	bool pauseFlag = false;
	bool fruitActive = false;

	board.printBoard(black_and_white);
	pacman.printCreature();

	while (pacman.getScore() < board.getNumOfCrumbs() && !didILose && continue_game) {
		getInput(pauseFlag, continue_game);
		if (!pauseFlag) {
			pacman.move(board);
			if (slowCreature % 2 == 0) {
				for (Ghost& ghost : ghosts) {
					ghost.move(board);
					ghost.setPacmanPoint(pacman.getCurrPoint());
				}
			}
			if (fruitActive) {
				if (slowCreature % 6 == 0)
					fruit.move(board);
				if (slowCreature % 203 == 0)
					hideFruit(fruitActive);
			}
			if (!fruitActive && (pacman.getScore() > 50) && (rand() % 59 == 0)) {
				fruitActive = true;
			}
			slowCreature++;
			creaturesCollision(didILose, fruitActive);
			board.printData(pacman.getScore() + pacman.getFruitScore(), pacman.getLife());
			if (save_mode)
				my_stream.push2Queue(my_stream.formatLine(pacman, ghosts, fruit, fruitActive));
		}
		else
			printGamePause();

		Sleep(100);
	}
	point_of_time = slowCreature;
}

char Regular_Mode::menu() {
	printMenu();
	char choice = _getch();
	char levelChoice;

	while (choice != '1' && choice != '2' && choice != '9') {
		switch (choice) {
		case '3':
			levelChoice = levelMenu();
			setGhostLevel(levelChoice);
			printMenu();
			break;
		case '4':
			chooseBoard();
			printMenu();
			break;
		case '8':
			printInstractions();
			printMenu();
			break;
		default:
			gotoxy(0, 19);
			cout << "Invalid choice. Choose a number from [1/2/3/4/8/9]" << endl;
			gotoxy(0, 0);
			break;
		}
		choice = _getch();
	}
	system("cls");
	return choice;
}

char Regular_Mode::levelMenu()
{
	printLevelMenu();
	char choice = _getch();

	while (choice != 'a' && choice != 'b' && choice != 'c') {
		gotoxy(0, 16);
		cout << "Invalid choice. Choose a letter from [a/b/c]" << endl;
		choice = _getch();
	}
	system("cls");
	return choice;
}

void Regular_Mode::chooseBoard() {
	system("cls");
	gotoxy(0, 0);

	printPacmanSign();
	cout << "Please insert screen name : " << endl;
	fileName.clear();
	cin >> fileName;
	system("cls");
}

void Regular_Mode::printGamePause() {
	setTextColor(Color::WHITE);
	gotoxy(0, board.getHeight() + 3);
	cout << "Game paused: press ESC to continue / press H to return the main menu";
	Sleep(650);
	cout << "\33[2K" << endl; // erase line from console
	Sleep(100);
}

void Regular_Mode::printMenu() {
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

void Regular_Mode::printLevelMenu() {
	system("cls");
	gotoxy(0, 0);
	printPacmanSign();
	cout << "Choose game level [a/b/c] " << endl
		<< " a.\tBEST " << endl
		<< " b.\tGOOD " << endl
		<< " c.\tNOVICE " << endl;
}

void Regular_Mode::printInstractions() {
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

