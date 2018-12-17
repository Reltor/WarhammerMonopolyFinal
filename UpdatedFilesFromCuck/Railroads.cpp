
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


Railroads::Railroads(string name)					//The constructors for Rail Roads
{
	Space();
	this->name = name;
}
Railroads::Railroads(string n, string a, int loc, int ao, bool mort, int pri, bool own)
	:numOwned{ ao }
{
	Space();
}

int Railroads::getRent(int rollDie)					//Returns the rent based on an array
{
	return rent[numOwned];
}

void Railroads::buyRR()								//Increments the array used for rent
{
	numOwned += 1;
}

void Railroads::setRent(std::array<int, 4> ren)		//Sets the vallues for the rent array
{
	rent[0] = ren[0];
	rent[1] = ren[1];
	rent[2] = ren[2];
	rent[3] = ren[3];
}


array<string, 11> Railroads::getTitleDeed()			//This lovely chunck of code displayes the information about the RialRoad on the right side of the screen
{
	ostringstream line1, line3, line4, line5, line6, line7, line8, line9, line10, line11;
	array<string, 11> displayArray{};
	displayArray[0] = "########################################";
	line1 << setw(40) << left << this->getName();
	displayArray[1] = line1.str();
	displayArray[2] = "########################################";
	line3 << left << boolalpha << "Owned: " << setw(40) << this->getOwned();
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
	line4 << setw(40) << left << propOwner;
	displayArray[4] = line4.str();

	line5 << left << "Rent: " << this->getRent();
	displayArray[5] = line5.str();

	line6 << left << "Price: " << this->getPrice();
	displayArray[6] = line6.str();

	return displayArray;
}

string Railroads::getSpaceType()								//Returns the type of space it is
{
	return this->spaceType;
}