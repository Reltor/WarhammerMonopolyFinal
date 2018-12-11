#ifndef SPACE_H
#define SPACE_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include "Player.h"

class Space
{
public:
	std::string getName();
	int getLocation();
	virtual int mort();
	virtual int getPrice();
	virtual int getRent();
	bool owned();
	Player* owner();
	Player* owner{};
	


protected:
	//double const price{};
	std::string name{};
	int location{};
	int houses{};
	int rent{};
	virtual void calculateRent(int dice);
	bool mortgage{};
	int const price{};
	bool owner{};
};

#endif
