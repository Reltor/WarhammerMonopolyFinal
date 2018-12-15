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

Properties::Properties(string n)// : Space()
	:rent { 10, 20, 40, 60, 100 }, houseCost{ 10 }, houses{ 0 }
{
	Space();
	name = n;
}

Properties::Properties()
{
}

int Properties::getPrice()
{
	return price;
}

int Properties::getRent(int dieRoll)
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
