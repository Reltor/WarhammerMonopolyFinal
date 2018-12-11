#include "Player.h"

void Player::setLocation(int l)
{
	location = l;
}

void Player::setMoney(int m)
{
	money = m;
}

void Player::rent(int r)
{
	money = money - r;
}

void Player::getMoney(int g)
{
	money = money + g;
}