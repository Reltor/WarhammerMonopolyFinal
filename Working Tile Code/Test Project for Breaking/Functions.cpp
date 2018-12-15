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

void Functions::buyHouse(Player & p, Properties & s)
{
	s.buyHouse();
	p.payRent(s.getHC());
}

void Functions::buyProperty(Player & p, Properties & s)
{
	p.payRent(s.getPrice());
	setOwnerShip(p, s);
	p.setProperties(&s);
}
void Functions::buyRR(Player & p, RailRoads & s)
{
	p.payRent(s.getPrice());
	setOwnerShip(p, s);
	s.buyRR();
	p.setProperties(&s);
}
void Functions::buyUtilities(Player & p, Utilities & s)
{
	p.payRent(s.getPrice());
	setOwnerShip(p, s);
	s.buyUtil();
	p.setProperties(&s);
}
void Functions::buyProperty(Player & p, Properties & s)
{
	p.payRent(s.getPrice());
	setOwnerShip(p, s);
	p.setProperties(&s);
}
