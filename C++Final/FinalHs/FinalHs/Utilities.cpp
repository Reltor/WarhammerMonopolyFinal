#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include "Space.h""
#include "Utilities.h"

int Utilities::mort()
{
	return price/2;
}

int Utilities::getPrice()
{
	return price;
}

int Utilities::getRent()
{
	return rent;
}

void Utilities::calculateRent(int dice)
{
	//if number of utilities == 1
	rent = 4 * dice;
	//if number of utilities == 2
	rent = 10 * dice;
}
