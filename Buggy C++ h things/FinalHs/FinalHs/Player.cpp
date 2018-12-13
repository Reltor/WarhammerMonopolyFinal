#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include <vector>
#include "Player.h"
#include "Properties.h"

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

void Player::setProperties(Properties* property)
{
	ownedProperties.push_back(property);
}