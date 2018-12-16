#ifndef RAILROADS_H
#define RAILROADS_H
#include <array>
#include <string>

#include "Space.h"

class Railroads : public Space
{
public:
	Railroads(std::string);
	Railroads(std::string n, std::string a, int loc, int ao, bool mort, int pri, bool own);
	int getRent(int = 0);
	void buyRR();
	void setRent(std::array<int, 4> ren);
	virtual std::array<std::string, 11> getTitleDeed();

private:
	int numOwned{};
	int rent[4]{};
	std::string spaceType = "Railroad";
};

#endif