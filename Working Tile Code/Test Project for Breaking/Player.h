#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include <vector>
#include "Space.h"
#//include "Properties.h"

class Player
{
public:
	Player();
	void setLocation(int);
	void setMoney(int);
	void payRent(int);
	void getMoney(int);
	std::string getName();
	int showMoney();
	void setProperties(Space*);


protected:
	int money;
	int remain;
	int location;
	std::string name;
	std::vector<Space*> ownedProperties;
};

