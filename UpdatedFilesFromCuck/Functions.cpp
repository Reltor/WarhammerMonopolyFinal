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

void Functions::payRent(Player & p, Space & s, int dieRoll)			//This function takes a reference to player and a space so that it can figure out how
{																	//much rent to charge the player... the dieRoll is a place holder, its used for utilities
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

void Functions::setOwnerShip(Player & p, Space & s)					//This function is used after a tile is bought to set its owner
{
	s.setOwner(p.getName());
}

void Functions::buyHouse(Player & p)								//This function is used to buy houses for properties
{
	vector<Space*> tempVec;											//Creates a temporary vector for the function
	tempVec = p.getProperties();
	for (int i{ 0 }; i < tempVec.size(); ++i)
	{
		cout << i + 1 << ") " << tempVec[i]->getName() << endl;		//Shows all the players properties
	}
	cout << "Select the property you would like to build a house on using a number: ";
	int choice;
	bool done = false;
	while (!done)
	{
		cin >> choice;
		choice -= 1;
		if (choice < 0 || choice > tempVec.size())					//Makes sure the number is within the array
		{
			cout << "Invalid number";
		}
		else if (tempVec[choice]->getSpaceType().compare("Property") == 0)		//Makes sure the property can be built on
		{
			tempVec[choice]->buyHouse();
			p.payRent(tempVec[choice]->getHC());
		}
		else
		{
			cout << "You can not build a house on this tile";		//For if the property can't be built on
		}
	}
}

void Functions::buyProperty(Player & p, Properties & s)				//This function is used to buy properties
{
	p.payRent(s.getPrice());
	setOwnerShip(p, s);
	p.setProperties(&s);
}
void Functions::buyRR(Player & p, Railroads & s)					//This function is used to buy railroads because the number of railroads you own changes the rent
{
	p.payRent(s.getPrice());
	setOwnerShip(p, s);
	s.buyRR();
	p.setProperties(&s);
}
void Functions::buyUtilities(Player & p, Utilities & s)				//This function is used to buy utilities because the number of utilities you own changes the rent
{
	p.payRent(s.getPrice());
	setOwnerShip(p, s);
	s.buyUtil();
	p.setProperties(&s);
}
void Functions::trade(Player & p, Player & t)						//This one was... fun, it is used for trading between players
{
	vector<Space*> aVec;											//The vector used by player a to temporaraly store their properties
	vector<Space*> bVec;											//The vector used by player b to temporaraly store their properties
	aVec = p.getProperties();
	vector<Space*> toTrade;											//Vector used to hold properties to trade
	bVec = t.getProperties();
	vector<Space*> tradeFor;										//Vector used to hole properties you are trading for
	cout << "This is a list of your current properties and if they are mortgaged" << endl << "____________________________________" << endl;

	bool done = false;
	int choice1;
	while (!done)
	{
		for (int i{ 0 }; i < aVec.size(); ++i)						//Shows all the property the current player has
		{
			Space s = *aVec[i];
			cout << i + 1 << ") " << s.getName() << "	Mortgaged: " << s.getMortPrint() << endl;
		}
		cout << endl << "Please input the properties you would like to trade, Enter 100 or greter if you are done: ";
		cin >> choice1;
		choice1 -= 1;
		if (choice1 >= 100)											//Checks the input and does what is needed
		{
			done = true;
		}
		else if (choice1 > aVec.size() || choice1 < 0)
		{
			cout << "invalid number" << endl;
			cin.clear();
		}
		else
		{
			toTrade.push_back(aVec[choice1]);						//Adds the selected property to the toTrade vector
			aVec.erase(aVec.begin() + choice1);
		}
	}
	cout << endl << "This is a list of the other players prperties and if they are morgaged" << endl << "____________________________________" << endl;

	done = false;
	int choice2;
	while (!done)
	{
		for (int i{ 0 }; i < bVec.size(); ++i)						//Shows all the properties the other player has
		{
			Space s = *bVec[i];
			cout << i + 1 << ") " << s.getName() << "	Mortgaged: " << s.getMortPrint() << endl;
		}
		cout << endl << "Please input the number of the property you would like to trade for, Enter 100 or greater to confirm: ";
		cin >> choice2;
		choice2 -= 1;
		if (choice2 >= 100)											//Checks the input and does what is needed
		{
			done = true;
		}
		else if (choice2 > bVec.size() || choice2 < 0)
		{
			cout << "invalid number" << endl;
			cin.clear();
		}
		else
		{
			tradeFor.push_back(bVec[choice2]);						//Adds selected property to the tradeFor vector
			bVec.erase(bVec.begin() + choice2);
		}
	}
	cout << "you have choosen to trade ";							//This shows the properties being traded
	for (int i{ 0 }; i < toTrade.size(); i++)
	{
		Space s = *toTrade[i];
		cout << s.getName() << "  ";
	}
	cout << " for ";
	for (int i{ 0 }; i < toTrade.size(); i++)
	{
		Space s = *tradeFor[i];
		cout << s.getName() << "  ";
	}
	cout << "Are you sure? (Y/N): ";								//Checks if the player wants to confirm the trade
	string finalChoice;
	done = false;
	while (!done)
	{
		cin >> finalChoice;
		if (finalChoice.compare("N") == 0 || finalChoice.compare("n") == 0)
		{
			finalChoice = "N";
			done = true;
		}
		else if (finalChoice.compare("Y") == 0 || finalChoice.compare("y") == 0)
		{
			finalChoice = "Y";
			done = true;
		}
		else
		{
			cout << "That is not a valid input (Y/N):" << endl;
		}
	}
	if (finalChoice.compare("Y") == 0)
	{
		cout << "Do you agree to this trade player 2? (Y/N): ";		//Checks if the trade works for the other player
		cin >> finalChoice;
		while (!done)
		{
			cin >> finalChoice;
			if (finalChoice.compare("Y") == 0 || finalChoice.compare("y") == 0)
			{
				for (int i{ 0 }; i < toTrade.size(); i++)
				{
					aVec.push_back(tradeFor[i]);

				}
				for (int i{ 0 }; i < toTrade.size(); i++)
				{
					bVec.push_back(toTrade[i]);
				}
				p.tradeProperties(aVec);							//Updates boths players properties lists with the new lists after trading
				t.tradeProperties(bVec);
				done = true;
			}
			else if (finalChoice.compare("N") == 0 || finalChoice.compare("n") == 0)
			{
				done = true;
			}
			else
			{
				cout << "That is not a valid input (Y/N):" << endl;
			}
		}
	}	
}

