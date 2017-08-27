#include "Player.h"
#include <iostream>

using namespace std;

Player::Player()
{
	_name = "No Name";
	_symbol = ' ';
}

void Player::setName(string name)
{
	_name = name;
}

void Player::setSymbol(char symbol)
{
	_symbol = symbol;
}

string Player::getName()
{
	return _name;
}

char Player::getSymbol()
{
	return _symbol;
}