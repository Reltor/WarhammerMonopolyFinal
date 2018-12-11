#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include "Space.h""
#include "Utilities.h"
#include "Properties.h"

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
	mortgage = true;
	return price/2;
}
int Properties::landOnTile()
{
	if (owned == true)
	{
		return getRent();
	}
	else
	{

	}

}

Player * Properties::getOwner()
{
	return nullptr;
}

void Properties::setOwner(Player* Owner)
{
	owner = Owner;
}
