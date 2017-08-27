#include <iostream>
#include <string>

#include "Game.h"

using namespace std;

int main()
{
	/* Welcome to Tic Tac Toe
	Enter the number of players between 2 and 5: numPlayers
	numPlayers it is!
	Enter the name of the first Player: player1.name
	what symbol would u like to use player1.symbol
	"repeat for other players"
	How wide do you want the board (3-15)? board.width
	how tall do u want the board (3-15)? board.height
	how many markers in a row do you want as a win condition (3-5):board.winCondition

	Player turns -- get placement (x, y) -- update board -- check for winner
	display winner -- play another game?
	*/

	Game game;
	game.playGame();
	return 0;
}