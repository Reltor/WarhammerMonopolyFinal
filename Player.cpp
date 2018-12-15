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

void Player::addMoney(int g)
{
	money = money + g;
}

std::string Player::getName()
{
	return name;
}

int Player::getMoney()
{
	return money;
}

void Player::setProperties(Space* property)
{
	ownedProperties.push_back(property);
}