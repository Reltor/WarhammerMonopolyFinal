#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include <vector>
#include "Space.h"
#include "Player.h"
#include "Properties.h"
#include "Utilities.h"
#include "RailRoads.h"

class Functions
{
public:
	static void payRent(Player& p, Space& s);
	static void setOwnerShip(Player& p, Space& s);
	static void buyHouse(Player& p, Properties& s);
	static void buyProperty(Player& p, Properties& s);
	static void buyRR(Player & p, RailRoads & s);
	static void buyUtilities(Player& p, Utilities& s);

};
