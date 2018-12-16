
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
#include <random>

class Functions
{
public:
	static void payRent(Player& p, Space& s, int dieRoll);
	static void setOwnerShip(Player& p, Space& s);
	static void buyHouse(Player& p, Properties& s);
	static void buyProperty(Player& p, Properties& s);
	static void buyRR(Player & p, Railroads & s);
	static void buyUtilities(Player& p, Utilities& s);
	static void trade(Player& p, Player& t);
	
};