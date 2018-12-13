#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include "Space.h"
#include "RailRoad.h"

void RailRoad::calculateRent(int rr)
{
	for (int i{ 1 };i <= rr;i++)
	{
		rent = rent * 2;
	}

}
