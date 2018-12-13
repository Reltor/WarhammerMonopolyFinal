#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include <vector>
#include "Player.h"


Player::Player()
{
	loc = 0;
}

int Player::getLoc()
{
	return loc;
}

void Player::setLoc(int newLoc)
{
	this->loc = newLoc;
}

void Player::setMoney(int m)
{
	money = m;
}

void Player::payRent(int r)
{
	money = money - r;
}

void Player::getMoney(int g)
{
	money = money + g;
}

std::string Player::getName()
{
	return name;
}

int Player::showMoney()
{
	return money;
}

void Player::setProperties(Space* property)
{
	ownedProperties.push_back(property);
}
