#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include <vector>
#include "Functions.h"
#include <random>

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
void Functions::buyRR(Player & p, Railroads & s)
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
	cout << "you have choosen to trade " << aVec[choice1] << " for " << bVec[choice2] << endl << "Are you sure? (Y/N): ";
	string finalChoice;
	while (!done)
	{
		cin >> finalChoice;
		if (finalChoice.compare("N") || finalChoice.compare("n"))
		{
			finalChoice = "N";
			done = true;
		}
		else if (finalChoice.compare("Y") || finalChoice.compare("y"))
		{
			finalChoice = "Y";
			done = true;
		}
		else
		{
			cout << "That is not a valic input (Y/N):" << endl;
		}
	}
	if (finalChoice.compare("N"))
	{
		cout << "Do you agree to this trade player 2? (Y/N): ";
		cin >> finalChoice;
		while (!done)
		{
			cin >> finalChoice;
			if (finalChoice.compare("N") || finalChoice.compare("n"))
			{
				Space* s = aVec[choice1];
				aVec[choice1] = bVec[choice2];
				bVec[choice2] = s;
				done = true;
			}
			else if (finalChoice.compare("Y") || finalChoice.compare("y"))
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

