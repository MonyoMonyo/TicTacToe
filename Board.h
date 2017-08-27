#pragma once
#include <vector>

class Board
{
public:
	Board();
	void clearBoard();
	void printBoard();
	void setWidth(int width);
	void setHeight(int height);
	void setWinCondition(int winCondition);
	bool updateBoard(int x, int y, char symbol);
	bool getWinCondition();
private:
	int _width;
	int _height;
	int _winCondition;
	char _board[15][15];
	bool _finalCheck;
};

