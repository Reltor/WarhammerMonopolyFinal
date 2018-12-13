#ifndef RAILROAD_H
#define RAILROAD_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include "Space.h"

class RailRoad : public Space
{
public:

protected:
	int rent{ 25 };
	void calculateRent(int rr);
};

#endif