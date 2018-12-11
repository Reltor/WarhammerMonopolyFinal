#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include "Space.h""

class Player
{
public:
	void setLocation(int l);
	void setMoney(int m);
	void rent(int);
	void getMoney(int);

protected:
	int money;
	int remain;
	int location;

};

#endif
