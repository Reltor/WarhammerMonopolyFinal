#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
//#include "Player.h"

class Space
{
public:
	Space();
	Space(std::string, std::string, int, int, int, bool, int, bool);
	std::string getName();
	int getLocation();
	virtual int mort();
	virtual int getPrice();
	virtual int getRent();
	bool getOwned();
	void setOwner(std::string);
	std::string getOwner();




protected:
	//double const price{};
	std::string owner{};
	std::string name{};
	std::string abv{};
	int location{};
	int houses{};
	int rent{};
	virtual void calculateRent(int dice);
	bool mortgage{};
	int price{};
	bool owned{};
};