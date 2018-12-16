#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include "Space.h"

class Utilities : public Space
{
public:
	Utilities(std::string);
	Utilities(std::string n, std::string a, int loc, int ao, bool mort, int pri, bool own);
	int getRent(int);
	void buyUtil();
	void setRent(std::array<int, 2> ren);
private:
	int numOwned{};
	int rent[2]{};
};
#endif