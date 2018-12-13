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

class Functions
{
public:
	static void payRent(Player& p, Space& s);
	static void setOwnerShip(Player& p, Space& s);

};
