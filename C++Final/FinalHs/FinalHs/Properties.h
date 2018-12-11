#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include "Space.h""
#include "Utilities.h"
#include "Player.h"

class Properties : public Space
{
public:
	int getPrice();
	int getRent();
	int mort();
	int landOnTile();
	Player* getOwner();
	void setOwner(Player*);
	Player* owner{};

protected:
	int const price{};
	bool owned{};
	int rent[5]{};
	bool mortgaged{};


};

#endif