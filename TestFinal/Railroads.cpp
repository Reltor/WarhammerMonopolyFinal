
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include <ostream>
#include <sstream>
#include "Railroads.h"
using namespace std;


Railroads::Railroads(string name)
{
	Space();
	this->name = name;
}
Railroads::Railroads(string n, string a, int loc, int ao, bool mort, int pri, bool own)
	:numOwned{ ao }
{
	Space();
}

int Railroads::getRent(int rollDie)
{
	return rent[numOwned];
}

void Railroads::buyRR()
{
	numOwned += 1;
}

void Railroads::setRent(std::array<int, 4> ren)
{
	rent[0] = ren[0];
	rent[1] = ren[1];
	rent[2] = ren[2];
	rent[3] = ren[3];
}