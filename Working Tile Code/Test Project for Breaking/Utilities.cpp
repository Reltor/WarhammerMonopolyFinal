#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include <ostream>
#include <sstream>
#include "RailRoads.h"
#include "Utilities.h"

using namespace std;

Utilities::Utilities(std::string n, std::string a, int loc, int ao, bool mort, int pri, bool own)
	:numOwned{ ao }
{
	Space();
}

int Utilities::getRent(int dieRoll)
{
	return dieRoll * rent[numOwned];
}

void Utilities::buyUtil()
{
	numOwned += 1;
}

void Utilities::setRent(std::array<int, 2> ren)
{
	rent[0] = ren[0];
	rent[1] = ren[1];
}

