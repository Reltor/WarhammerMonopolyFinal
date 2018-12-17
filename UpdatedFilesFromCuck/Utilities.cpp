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
#include "Player.h"

using namespace std;

Utilities::Utilities(std::string n, std::string a, int loc, int ao, bool mort, int pri, bool own)		//The constructor for utilities
	:numOwned{ ao }
{
	Space();
}

int Utilities::getRent(int dieRoll)									//Returns the rent for utilities, multiplies the dieRoll by an int in an array
{
	return dieRoll * rent[numOwned];
}

void Utilities::buyUtil()											//Increments the array for rent cost
{
	numOwned += 1;
}

void Utilities::setRent(std::array<int, 2> ren)						//sets the rent array
{
	rent[0] = ren[0];
	rent[1] = ren[1];
}
Utilities::Utilities(string name)									//Another cunstructor for Utilities
{
	Space();
	this->name = name;
}

array<string, 11> Utilities::getTitleDeed()							//This lovely chunck of code displayes the information about the utility on the right side of the screen
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

	line5 << left << "Rent with one Utility Owned: 4 times the roll of the dice";
	displayArray[5] = line5.str();

	line6 << left << "Rent with two Utilities Owned: 10 times the roll of the dice";
	displayArray[6] = line6.str();

	line7 << left << "Price: " << this->getPrice();
	displayArray[7] = line7.str();
	return displayArray;
}