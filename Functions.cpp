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

void Functions::payRent(Player & p, Space & s, int dieRoll)
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
			p.payRent(s.getRent(dieRoll));
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
void Functions::trade(Player & p, Player & t)
{
	vector<Space*> aVec;
	vector<Space*> bVec;
	aVec = p.getProperties();
	bVec = t.getProperties();
	cout << "This is a list of your current properties and if they are mortgaged" << endl << "____________________________________" << endl;
	for (int i{ 0 }; i < p.getProperties().size(); i++)
	{
		Space s = *aVec[i];
		cout << i + 1 << ") " << s.getName() << "	Mortgaged: " << s.getMortPrint() << endl;
	}
	cout << endl << "Please input the number of the property you would like to trade: ";
	bool done = false;
	int choice1;
	while (!done)
	{
		cin >> choice1;
		choice1 -= 1;
		if (choice1 > aVec.size() || choice1 < 0)
		{
			cout << "invalid number" << endl;
			cin.clear();
		}
		else
		{
			done = true;
		}
	}
	cout << endl << "This is a list of the other players prperties and if they are morgaged" << endl << "____________________________________" << endl;
	for (int i{ 0 }; i < t.getProperties().size(); i++)
	{
		Space s = *bVec[i];
		cout << i + 1 << ") " << s.getName() << "	Mortgaged: " << s.getMortPrint() << endl;
	}
	cout << endl << "Please input the number of the property you would like to trade: ";
	done = false;
	int choice2;
	while (!done)
	{
		cin >> choice2;
		choice2 -= 1;
		if (choice2 > bVec.size() || choice2 < 0)
		{
			cout << "invalid number" << endl;
			cin.clear();
		}
		else
		{
			done = true;
		}
	}
	cout << "you have choosen to trade " << aVec[choice1]->getName() << " for " << bVec[choice2]->getName() << endl << "Are you sure? (Y/N): ";
	string finalChoice;
	done = false;
	while (!done)
	{
		cin >> finalChoice;
		if (finalChoice.compare("Y") == 0 || finalChoice.compare("y") == 0)
		{
			finalChoice = "Y";
			done = true;
		}
		else if (finalChoice.compare("N") == 0 || finalChoice.compare("n") == 0)
		{
			finalChoice = "N";
			done = true;
		}
		else
		{
			cout << "That is not a valic input (Y/N):" << endl;
		}
	}
	if (finalChoice.compare("Y") == 0)
	{
		done = false;
		cout << "Do you agree to this trade player 2? (Y/N): ";
		while (!done)
		{
			cin >> finalChoice;
			if (finalChoice.compare("Y") == 0 || finalChoice.compare("y") == 0)
			{
				p.tradeProperties(bVec[choice2], choice1);
				t.tradeProperties(aVec[choice1], choice2);
				done = true;
			}
			else if (finalChoice.compare("N") == 0 || finalChoice.compare("n") == 0)
			{
				done = true;
			}
			else
			{
				cout << "That is not a valic input (Y/N):" << endl;
			}
		}
	}
}