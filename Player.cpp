#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include <vector>
#include "Player.h"
//#include "Properties.h"

using namespace std;

Player::Player()
	:money{ 100 }, remain{ 1 }, location{ 2 }, name{ "john" } {}

void Player::setLocation(int l)
{
	location = l;
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

const vector<Space*> Player::getProperties()
{
	return ownedProperties;
}

void Player::tradeProperties(Space * s, int position)
{
	ownedProperties[position] = s;
}
