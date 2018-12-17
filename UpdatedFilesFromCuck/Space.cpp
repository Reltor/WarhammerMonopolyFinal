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
Space::Space()												//The 3 constructors we have for spaces the first two are for testing the last one is for the game
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


std::string Space::getName()							//Returns the name of the space
{
	return name;
}

int Space::getLocation()								//Not used but would return the location of the space
{
	return location;
}

int Space::mort()										//Returns the mortgage value and sets the mortgage flag to true
{
	this->mortgage = true;
	return 25;
}

void Space::unMort()									//Sets the morgage flag to false
{
	this->mortgage = false;
}

int Space::getPrice()									//Returns the price of the space
{
	return price;
}

int Space::getRent(int dieRoll)							//Returns the rent for the space, the dieRoll is a place holder used for utilities
{
	return rent;
}

bool Space::getOwned()									//Returns the owned flag
{
	return owned;
}

void Space::setOwner(std::string p)						//Sets the owner of the space and the owned flag to true
{
	owner = p;
	owned = true;
}


string Space::getOwner()								//Returns the owner of the tile as a string
{
	return owner;
}


array<string,11> Space::getTitleDeed()					//This lovely chunck of code displayes the information about the space on the right side of the screen
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

string Space::getMortPrint()								//Used in the trading function to show if the property is mortgaged or not
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

bool Space::getMort()										//Returns the true/false flag of the space's mortgage
{
	return mortgage;
}

void Space::calculateRent(int dice)							//Used by utilities for calculating rent
{
	rent = dice;
}

string Space::getSpaceType()								//Returns the type of space it is
{
	return this->spaceType;
}

void Space::setOwned()										//Sets the owned flag to true
{
	this->owned = true;
}

void Space::buyHouse()										//Placeholder function for properties, usd to buy houses
{
}

int Space::getHC()											//Placeholder function for properties, used to get the price of a house
{
	return 0;
}
