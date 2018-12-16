#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include <vector>
#include "Space.h"

class Player
{
public:
	Player();
	Player(std::string);
	int getLoc();
	void setLoc(int);
	void setMoney(int);
	void payRent(int);
	void addMoney(int);
	std::string getName();
	int showMoney();
	int getState();
	void setState(int state = 1);
	bool allMortgaged();
	void setProperties(Space*);
	const std::vector<Space*> getProperties();
	void setName(std::string);
	void resetDoubles();
	void addDouble();
	int getDoubles();
	void jail();
	void removeFromJail();
	bool getJailedState();
	void setLastRoll(int);
	int getLastRoll();
	int netWorth();
	std::string getIcon();
	void setIcon(std::string);

private:
	int money;
	int remain;
	int loc;
	std::string name;
	std::vector<Space*> ownedProperties;
	int numDoubles = 0;
	bool jailed = false;
	int lastRoll;
	std::string icon;
};

#endif