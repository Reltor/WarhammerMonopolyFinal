#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include <vector>
#include "Space.h"

class Player
{
public:
	Player();
	int getLoc();
	void setLoc(int);
	void setMoney(int);
	void payRent(int);
	void getMoney(int);
	std::string getName();
	int showMoney();
private:
	int money;
	int remain;
	int loc;
	std::string name;
	void setProperties(Space*);
	std::vector<Space*> ownedProperties;
};

#endif