#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include "Space.h"
#include "Player.h"

using namespace std;
Space::Space()
	:name{ "JavaIsBetter" }, abv{ "JIB" }, location{ 2 }, houses{ 0 }, rent{ 100 }, mortgage{ false }, price{ 50 }, owned{ false }
{
}

std::string Space::getName()
{
	return name;
}

int Space::getLocation()
{
	return location;
}

int Space::mort()
{
	return 25;
}

int Space::getPrice()
{
	return price;
}

int Space::getRent()
{
	return rent;
}

bool Space::getOwned()
{
	return owned;
}

void Space::setOwner(std::string p)
{
	owner = p;
	owned = true;
}


string Space::getOwner()
{
	return owner;
}

void Space::calculateRent(int dice)
{
	rent = dice;
}
