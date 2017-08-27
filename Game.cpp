#include "Game.h"
#include "Board.h"
#include "Player.h"

#include <iostream>

using namespace std;

Game::Game()
{
}

void Game::playGame()
{
	Player players[5];
	cout << "Welcome to Tic Tac Toe!\n" << endl;
	cout << "Enter the number of players you wish to have (between 2 and 5)" << endl;
	cin >> numPlayers;
	while (numPlayers != 2 && numPlayers != 3 && numPlayers != 4 && numPlayers != 5)
	{
		cout << "Pick a number between 2 and 5: " << endl;
		cin >> numPlayers;
	}
	cout << "Please enter the name of the first player: " << endl;
	cin >> name;
	players[0].setName(name);
	cout << "Welcome " << name << endl << "Please enter the symbol of the first player : " << endl;
	cin >> symbol;
	players[0].setSymbol(symbol);

	for (int i = 1; i < numPlayers; i++)
	{
		cout << "Please enter the name of the next player: " << endl;
		cin >> name;
		players[i].setName(name);
		cout << "Welcome " << name << endl;
		cout << "Please enter the symbol of the next player:" << endl;
		cin >> symbol;
		players[i].setSymbol(symbol);
	}
	cout << "How wide do you want the board? (3-15)";
	cin >> boardwidth;
	cout << "How tall do you want the board? (3-15)";
	cin >> boardheight;

	Board board;
	board.setWidth(boardwidth);
	board.setHeight(boardheight);
	board.clearBoard();

	cout << "How many markers in a row do you want as a win condition? (3-5)";
	cin >> winCondition;
	board.setWinCondition(winCondition);

	cout << "Heres the board. Enjoy!" << endl << endl;
	board.printBoard();
	isDone = false;
	counter = 0;
	plays = boardwidth * boardheight;

	while (isDone == false)
	{
		for (int i = 0; i < 5; i++)
		{
			if (players[i].getName() == "No Name")
			{
				continue;
			}
			else
			{
				cout << endl << players[i].getName() << "'s turn!" << endl << endl;
				do
				{
					cout << "Enter the x-coordinate of your move" << endl;
					cin >> xcoord;
					cout << "Enter the y-coordinate of your move" << endl;
					cin >> ycoord;
				}
				while (board.updateBoard(ycoord, xcoord, players[i].getSymbol()) == false);
				board.printBoard();
				counter++;
				if (counter == plays)
				{
					cout << "No one won!\n Game over!\n";
					isDone = true;
					break;
				}
				//Check win condition
				if (board.getWinCondition() == true)
				{
					cout << players[i].getName() << " wins! Game over!" << endl;
					isDone = true;
					break;
				}
			}

		}
	}
	cout << "Would you like to play another game? Y/N" << endl;
	char a;
	cin >> a;
	if (a == 'Y' || a == 'y')
	{
		playGame();
	}
	else
	{
		cout << "Goodbye! " << endl;
		system("pause");
	}
}
