#include "Regular_Mode.h"

void Regular_Mode::runGame() {
	char choice;

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
			text_printer.printExit();
			ShowConsoleCursor(true); // reveal console cursor
			return;
		}

		fileName = "";
		screenNames.clear();
		continue_game = true;
	}
}

void Regular_Mode::run() {
	bool didILose = false;

	readScreens();
	if (continue_game)
	{
		for (string& screen : screenNames)
		{
			resetGame(screen);
			if (!board.isValidScreen())
				return;

			runScreen(didILose);
			if (!continue_game)
				break;

			if (save_mode)
				my_stream.write2Files(screen, didILose, point_of_time, pacman.getScore() + pacman.getFruitScore());

			if (!didILose)
				winGame();
			else {
				gameOver();
				break;
			}
		}
		if (!didILose && continue_game)
			text_printer.printMsg("You won the last screen, congrats !\n");
	}
}

void Regular_Mode::runScreen(bool& didILose)
{
	bool pauseFlag = false;
	bool fruitActive = false;

	board.printBoard(black_and_white);
	pacman.printCreature();

	while (pacman.getScore() < board.getNumOfCrumbs() && !didILose && continue_game) {
		getInput(pauseFlag, continue_game);
		if (!pauseFlag) {
			pacman.move(board);
			if (point_of_time % 2 == 0) {
				for (Ghost& ghost : ghosts) {
					ghost.move(board);
					ghost.setPacmanPoint(pacman.getCurrPoint());
				}
			}
			if (fruitActive) {
				if (point_of_time % 6 == 0)
					fruit.move(board);
				if (point_of_time % 203 == 0)
					hideFruit(fruitActive);
			}
			if (!fruitActive && (pacman.getScore() > 50) && (rand() % 59 == 0)) {
				fruitActive = true;
			}
			point_of_time++;

			if (save_mode)
				my_stream.push2Queue(my_stream.formatLine(pacman, ghosts, fruit, fruitActive));

			creaturesCollision(didILose, fruitActive);

			text_printer.printData(pacman.getScore() + pacman.getFruitScore(), pacman.getLife(), board.getLegendPos());
		}
		else
			text_printer.printGamePause(board.getHeight());

		Sleep(100);
	}
}

void Regular_Mode::resetGame(string screen) {
	Game_Logic::resetGame(screen);
	for (int i = 0; i < board.getNumOfGhosts(); i++) {
		ghosts[i].setGhostLevel(ghostLevel);
	}
}

char Regular_Mode::menu() {
	text_printer.printMenu();
	char choice = _getch();
	char levelChoice;

	while (choice != '1' && choice != '2' && choice != '9') {
		switch (choice) {
		case '3':
			levelChoice = levelMenu();
			setGhostLevel(levelChoice);
			text_printer.printMenu();
			break;
		case '4':
			chooseBoard();
			text_printer.printMenu();
			break;
		case '8':
			text_printer.printInstractions();
			text_printer.printMenu();
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
	text_printer.printLevelMenu();
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

	text_printer.printPacmanSign();
	cout << "Please insert screen name : " << endl;
	fileName.clear();
	cin >> fileName;
	system("cls");
}







