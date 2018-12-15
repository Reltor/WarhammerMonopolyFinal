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

using namespace std;

RailRoads::RailRoads(string n, string a, int loc, int ao, bool mort, int pri, bool own)
	:numOwned{ ao }
{
	Space();
}

int RailRoads::getRent(int rollDie)
{
	return rent[numOwned];
}

void RailRoads::buyRR()
{
	numOwned += 1;
}

void RailRoads::setRent(std::array<int, 4> ren)
{
	rent[0] = ren[0];
	rent[1] = ren[1];
	rent[2] = ren[2];
	rent[3] = ren[3];
}
