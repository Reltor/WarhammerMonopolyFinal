#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include "Space.h""

class Utilities : public Space
{
public:
	int mort();
	int getPrice();
	int getRent();

protected:
	void calculateRent(int dice);
	int rent{};
};

#endif