#ifndef RAILROADS_H
#define RAILROADS_H

#include "Space.h"

class Railroads : public Space
{
public:
	Railroads(std::string);
	Railroads(std::string n, std::string a, int loc, int ao, bool mort, int pri, bool own);
	int getRent(int);
	void buyRR();
	void setRent(std::array<int, 4> ren);

private:
	int numOwned{};
	int rent[4]{};
	std::string spaceType = "Railroad";
};

#endif