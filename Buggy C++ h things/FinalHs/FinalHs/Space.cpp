#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include "Space.h"
#include "Player.h"


Space::Space()
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
	return 0;
}

int Space::getPrice()
{
	return 0;
}

int Space::getRent()
{
	return 0;
}

bool Space::getOwned()
{
	return owned;
}

void Space::setOwner(Player* player)
{
	owner = player;
	owned = true;
}

Player* Space::getOwner()
{
	return owner;
}

void Space::calculateRent(int dice)
{
	rent = 0;
}
