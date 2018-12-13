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
#include "Properties.h"

class Player
{
public:
	void setLocation(int);
	void setMoney(int);
	void payRent(int);
	void getMoney(int);


protected:
	int money;
	int remain;
	int location;
	void setProperties(Properties*);
	std::vector<Properties*> ownedProperties;
};

#endif
