#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include "Space.h"
#include "Player.h"
#include <sstream>

using namespace std;
Space::Space()
	:name{ "JavaIsBetter" }, abv{ "JIB" }, location{ 2 }, houses{ 0 }, rent{ 100 }, mortgage{ false }, price{ 50 }, owned{ false }
{
}
Space::Space(string name)
	: name{ name }, abv{ "JIB" }, location{ 2 }, houses{ 0 }, rent{ 100 }, mortgage{ false }, price{ 50 }, owned{ false }
{

}

Space::Space(string n, string a, int loc, int house, int ren, bool mort, int pri, bool own)
	: name{ n }, abv{ a }, location{ loc }, houses{ house }, rent{ ren }, mortgage{ mort }, price{ pri }, owned{ own }
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
	this->mortgage = true;
	return 25;
}

void Space::unMort()
{
	this->mortgage = false;
}

int Space::getPrice()
{
	return price;
}

int Space::getRent(int dieRoll)
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


array<string,11> Space::getTitleDeed()
{
	ostringstream line1, line3, line4, line5, line6, line7, line8, line9, line10, line11;
	array<string,11> displayArray{};
	displayArray[0] = "########################################";
	line1 << setw(40) << left << this->getName(); 
	displayArray[1] = line1.str();
	displayArray[2] = "########################################";
	line3 << left  << boolalpha<< "Owned: " << setw(40) <<   this->getOwned();
	displayArray[3] = line3.str();
	string propOwner;
	if (this->getOwned() == false)
	{
		propOwner = "Owner: None";
	}
	else
	{
		propOwner = "Owner :" + this->getOwner();
	}
	line4 << setw(40)<< left << propOwner;
	displayArray[4] = line4.str();

	return displayArray;
}

string Space::getMortPrint()
{
	if (mortgage)
	{
		return "yes";
	}
	else
	{
		return "no";
	}
}

bool Space::getMort()
{
	return mortgage;
}

void Space::calculateRent(int dice)
{
	rent = dice;
}

string Space::getSpaceType()
{
	return this->spaceType;
}

void Space::setOwned()
{
	this->owned = true;
}