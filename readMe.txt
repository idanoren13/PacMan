
PacMan Ex2

Idan Oren       209007921
Sagi Goldfarb   316496173

Additions:
	- Colors and B&W option to the game
	- Blinking pause game message

TODO:
	- Fix Ghost::smartGhost()
	- Change enum Shape to enum class Shape
	- Handle edge cases on Board
	- Switch keys back to default before submitting

DONE:
	- Game_Logic::run() - game should end when all bread crumbs are eaten and not when score equales num of crumbs. 
	- Game_Logic::creaturesCollision() - at the moment we're changing score from two different places, here and in pacman.move()
	- NOTICE ! - Game_Logic should be more dynamic, we might get different number of ghosts from different files
	- num of bread crumbs, board size, etc. should be dynamic as well
	- In some cases game doesn't end when all bread crumbs are eaten
	- Game_Logic::run() - function too big, split it only after solving ghosts AI
	- Game_Logic::fruitPacmanCollision() - pacman still disapear when fruit "eats" pacman when pacman isn't moving


