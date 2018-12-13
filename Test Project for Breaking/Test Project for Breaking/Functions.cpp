#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include <vector>
#include "Functions.h"

using namespace std;

void Functions::payRent(Player & p, Space & s)
{
	if (s.getOwned() == true)
	{
		string sOwner = s.getOwner();
		string pName = p.getName();
		if (sOwner.compare(pName) == 0)
		{
		}
		else
		{
			p.payRent(s.getRent());
		}
	}
}

void Functions::setOwnerShip(Player & p, Space & s)
{
	s.setOwner(p.getName());
}
