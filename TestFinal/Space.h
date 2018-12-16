#ifndef SPACE_H
#define SPACE_H

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
	Space(std::string name);
	Space(std::string, std::string, int, int, int, bool, int, bool);

	std::string getName();
	int getLocation();
	virtual int mort();
	virtual void unMort();
	virtual int getPrice();
	virtual int getRent(int);
	virtual std::array<std::string,11> getTitleDeed();
	bool getOwned();
	void setOwner(std::string);
	std::string getOwner();
	std::string getMortPrint();
	std::string getSpaceType();
	bool getMort();
	void setOwned();
	//Space & operator=(Space &&obj) = default;




protected:
	//double const price{};
	std::string owner;
	std::string name;
	std::string abv;
	int location;
	int houses;
	int rent;
	bool mortgage;
	int  price;
	bool owned;
	virtual void calculateRent(int dice);
	std::string spaceType = "Space";

};
#endif