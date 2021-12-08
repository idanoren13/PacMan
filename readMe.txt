
PacMan Ex2

Idan Oren       209007921
Sagi Goldfarb   316496173

Additions:

	- colors and B&W option to the game
	- blinking pause game message

TODO:
	- Game_Logic::run() - game should end when all bread crumbs are eaten and not when score equales num of crumbs. 
	- Game_Logic::creaturesCollision() - at the moment we're changing score from two different places, here and in pacman.move()
	- Game_Logic::fruitPacmanCollision() - pacman still disapear when fruit "eats" pacman when pacman isn't moving
	- Game_Logic::run() - function too big, split it only after solving ghosts AI
	- Change enum Shape to enum class Shape
	- NOTICE ! - Game_Logic should be more dynamic, we might get different number of ghosts from different files
	- Num of bread crumbs, board size, etc. should be dynamic as well