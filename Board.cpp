#include "Board.h"

#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setw;

Board::Board()
{
	clearBoard();
}

void Board::setWidth(int width)
{
	_width = width;
}

void Board::setHeight(int height)
{
	_height = height;
}

void Board::setWinCondition(int winCondition)
{
	_winCondition = winCondition;
}

void Board::clearBoard()
{
	for (int i = 0; i < _width; i++)
	{
		for (int j = 0; j < _height; j++)
		{
			_board[i][j] = ' ';
		}
	}
}

void Board::printBoard()
{
	cout << endl;
	cout << "  |";
	for (int k = 0; k < _width; k++)
	{
		cout << setw(2) << k + 1 << '|';
	}
	cout << endl;
	for (int x = 0; x < _height; x++)
	{
		cout << setw(2) << x + 1 << "|";
		for (int y = 0; y < _width; y++)
		{
			cout << setw(2) << _board[x][y] << '|';
		}
		cout << endl;
	}
}

bool Board::updateBoard(int x, int y, char symbol)
{
	if (_board[x - 1][y - 1] != ' ')
	{
		cout << "Choose an unoccupied spot." << endl;
		return false;
	}
	_board[x - 1][y - 1] = symbol;
	return true;
}

bool Board::getWinCondition()
{
	//Checking for a win condition in columns
	for (int i = 0; i < _width; i++) // x
	{
		for (int j = 0; j < _height; j++) // ignore // y
		{
			if (_board[i][j] != ' ') // not empty
			{
				for (int k = 1; k < _winCondition; k++) // check n in a row
				{
					// rows
					if (_board[i][j] == _board[i][j + k]) // x x x x x
					{
						if (k == _winCondition - 1)
						{
							return true;
						}
					}
					else
					break;
				}
				// columns
				for (int k = 1; k < _winCondition; k++) // check n in a row
				{
					if (_board[i][j] == _board[i + k][j]) // x x x x x
					{
						if (k == _winCondition - 1)
						{
							return true;
						}
					}
					else
						break;
				}
				// left diagonal
				for (int k = 1; k < _winCondition; k++) // check n in a row
				{
					if (_board[i][j] == _board[i + k][j + k]) // x x x x x
					{
						if (k == _winCondition - 1)
						{
							return true;
						}
					}
					else
						break;
				}
				// right diagonal
				for (int k = 1; k < _winCondition; k++) // check n in a row
				{
					if (_board[i][j] == _board[i + k][j - k]) // x x x x x
					{
						if (k == _winCondition - 1)
						{
							cout << "right";
							return true;
						}
					}
					else
						break;
				}// end k
			}// end if empty
		} // end j
	}// end i
	return false;
}