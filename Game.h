#pragma once
#include <string>

class Game
{
public:
	Game();
	void playGame();
private:
	int numPlayers, boardwidth, boardheight, counter, plays, winCondition, xcoord, ycoord;
	std::string name;
	char symbol;
	bool isDone;
};

