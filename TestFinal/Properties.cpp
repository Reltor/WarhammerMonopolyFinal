#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include <ostream>
#include <sstream>
#include "Space.h"
#include "Properties.h"

using namespace std;

Properties::Properties()// : Space()
	:rent{ 10,20,40,60,100 }, houseCost{ 10 }, houses{ 0 }, price {0}
{

}

Properties::Properties(string name)
	: rent{ 0,20,40,60,100 },houseCost{ 10 }, houses{ 0 }, price{0}
{
	
	this->name = name;
}

int Properties::getPrice()
{
	return price;
}

int Properties::getRent()
{
	return rent[houses];
}

int Properties::mort()
{
	Properties::mortgaged = true;
	return price / 2;
}


/*std::string Properties::toString()
{
	if (mortgaged == true)
	{
		string mort = "Mortgaged: yes";
	}
	else
	{
		string mort = "Mortgaged: no";
	}
	std::ostringstream card;
	card << "[" << setw(20) << name << "]/n" << "|" << setw(20) << "SetGoesHere" << "|" << endl;
	card << "|" << setw(20) << getRent(houses) << "|/n" << "|" << setw(20) << houseCost << "|" << endl;
	card << "|" << setw(20) << "" << "|/n" << "|" << setw(20) << "" << "|/n" << "|" << setw(20) << mort << "|" << endl;
	card << "--------------------";
	std::string str = card.str();
	return str;
}*/

void Properties::buyHouse()
{
	houses += 1;
}

int Properties::getHC()
{
	return houseCost;
}




array<string, 11> Properties::getTitleDeed() 
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

	line7 << left << "House Cost: " << this->getHC();
	return displayArray;
}