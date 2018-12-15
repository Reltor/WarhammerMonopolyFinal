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
	:name{ "JavaBeBetta" }, abv{ "JBB" }, location{ 2 }, houses{ 0 }, rent{ 100 }, mortgage{ false }, price{ 10 }, owned{ false }
{
}

Space::Space(string n,string a, int loc, int house, int ren, bool mort, int pri, bool own)
	:name{ n }, abv{ a }, location{ loc }, houses{ house }, rent{ ren }, mortgage{ mort }, price{ pri }, owned{ own }
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
