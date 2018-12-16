#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include <vector>
#include "Player.h"

using namespace std;

Player::Player()
	:money{ 1000 }, remain{ 1 }, loc{ 0 }, name{ "john" } 
{

	ownedProperties.resize(0);
}

Player::Player(string n)
	: money{ 1000 }, remain{ 1 }, loc{ 0 }, name{ n }
{
	ownedProperties.resize(0);
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

void Player::addMoney(int g)
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


int Player::getState()
{
	return this->remain;
}


void Player::setState(int state)
{
	this->remain = state;
}

bool Player::allMortgaged()
{
	int ownedTotal = 0;
	for (Space* x : this->ownedProperties)
	{
		ownedTotal += x->mort();
	}
	return true;
}

const vector<Space*> Player::getProperties()
{
	return this->ownedProperties;
}

void Player::setName(string n)
{
	this->name = n;
}

void Player::resetDoubles()
{
	this->numDoubles = 0;
}

void Player::addDouble()
{
	this->numDoubles += 1;
}

int Player::getDoubles()
{
	return this->numDoubles;
}

void Player::jail()
{
	this->jailed = true;
	this->setLoc(10);
}

void Player::removeFromJail()
{
	this->jailed = false;
}

bool Player::getJailedState()
{
	return this->jailed;
}

void Player::setLastRoll(int roll)
{
	this->lastRoll = roll;
}

int Player::getLastRoll()
{
	return this->lastRoll;
}