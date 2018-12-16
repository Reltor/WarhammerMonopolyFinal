#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include "Space.h"
#include "Player.h"

class Properties : public Space
{
public:
	Properties();
	Properties(std::string);
	int getPrice();
	int getRent();
	int mort();
	void buyHouse();
	int getHC();
	virtual std::array<std::string, 11> getTitleDeed();

protected:
	int const price;
	bool owned;
	int rent[5];
	bool mortgaged;
	int const houseCost;
	int houses;
	std::string owner;
	std::string spaceType = "Property";
};