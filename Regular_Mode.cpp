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
			printer.printExit();
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
			printer.printMsg("You won the last screen, congrats !\n");
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
			printer.printGamePause(board.getHeight());

		Sleep(100);
	}
	point_of_time = slowCreature;
}

void Regular_Mode::resetGame(string screen) {
	Game_Logic::resetGame(screen);
	for (int i = 0; i < board.getNumOfGhosts(); i++) {
		ghosts[i].setGhostLevel(ghostLevel);
	}
}

char Regular_Mode::menu() {
	printer.printMenu();
	char choice = _getch();
	char levelChoice;

	while (choice != '1' && choice != '2' && choice != '9') {
		switch (choice) {
		case '3':
			levelChoice = levelMenu();
			setGhostLevel(levelChoice);
			printer.printMenu();
			break;
		case '4':
			chooseBoard();
			printer.printMenu();
			break;
		case '8':
			printer.printInstractions();
			printer.printMenu();
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
	printer.printLevelMenu();
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

	printer.printPacmanSign();
	cout << "Please insert screen name : " << endl;
	fileName.clear();
	cin >> fileName;
	system("cls");
}







