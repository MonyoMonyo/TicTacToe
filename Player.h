#pragma once
#include <string>

class Player
{
public:
	Player();
	void setName(std::string name);
	void setSymbol(char symbol);
	char getSymbol();
	std::string getName();
private:
	std::string _name;
	char _symbol;
};
