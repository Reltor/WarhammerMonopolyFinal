#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include "Space.h"

class RailRoads : public Space
{
public:
	RailRoads(std::string n, std::string a, int loc, int ao, bool mort, int pri, bool own);
	int getRent(int);
	void buyRR();
	void setRent(std::array<int, 4> ren);

private:
	int numOwned{};
	int rent[4]{};

};

