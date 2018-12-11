#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include "Space.h""
#include "Properties.h"

class Game
{
public:
	bool move();
	Properties* buyFromBank();
	void chargeRent();
	int rollDie();
	void goToJail();
	void display();
	void createBoard();
	void skipAhead();
	void mortgage();
	Properties* auction();
	void landOnTile();

protected:
	const int playerMin;
	const int playerMax;
	//array board;

};

#endif