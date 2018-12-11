#ifndef BUILDABLEPROPERTIES_H
#define BUILDABLEPROPERTIES_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include "Space.h""
#include "Properties.h"

class BuildableProperties : public Properties
{
public:
	void build();

protected:
	int const housePrice{};
	int houses{};
	bool mortgage{};

	void calculateRent();
};

#endif