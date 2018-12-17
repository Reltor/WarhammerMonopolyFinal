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
	:money{ 1000 }, remain{ 1 }, loc{ 0 }, name{ "john" }						//There are a couple constructors one is for testing porpoises the other is for the game
{

	ownedProperties.resize(0);
}

Player::Player(string n)
	: money{ 1000 }, remain{ 1 }, loc{ 0 }, name{ n }
{
	ownedProperties.resize(0);
}

int Player::getLoc()															//Returns the location of the player
{
	return loc;
}

void Player::setLoc(int newLoc)													//Sets the player's location
{
	this->loc = newLoc;
}

void Player::setMoney(int m)													//Sets the Player's money
{
	money = m;
}

void Player::payRent(int r)														//Used to pay rent and buy tiles
{
	money = money - r;
}

void Player::addMoney(int g)													//Used to get money from rent
{
	money = money + g;
}

std::string Player::getName()													//Returns the player's name
{
	return name;
}

int Player::showMoney()															//Returns the money the player has
{
	return money;
}

void Player::setProperties(Space* property)										//Adds properties to the player's Space array, used when buying tiles
{
	ownedProperties.push_back(property);
}


int Player::getState()															//Cheks if the player is still in the game
{
	return this->remain;
}


void Player::setState(int state)												//Changes the player's remain stat for if they lose
{
	this->remain = state;
}

bool Player::allMortgaged()														//Checks if all the player's properties are mortgaged
{
	int ownedTotal = 0;
	for (Space* x : this->ownedProperties)
	{
		ownedTotal += x->mort();
	}
	return true;
}

const vector<Space*> Player::getProperties()									//Returns the vector of properties the player owns
{
	return this->ownedProperties;
}

void Player::setName(string n)													//Sets the player's name
{
	this->name = n;
}

void Player::resetDoubles()														//Resets the count for doubles being rolled
{
	this->numDoubles = 0;
}

void Player::addDouble()														//Adds the the count for doubles being rolled
{
	this->numDoubles += 1;
}

int Player::getDoubles()														//Returns the number of doubles rolled
{
	return this->numDoubles;
}

void Player::jail()																//Puts the player in jail and flags them as jailed
{
	this->jailed = true;
	this->setLoc(10);
}

void Player::removeFromJail()													//Resets the jailed flag for the player
{
	this->jailed = false;
}

bool Player::getJailedState()													//Returns weather the player is jailed or not
{
	return this->jailed;
}

void Player::setLastRoll(int roll)												//Sets the last number the player rolled used for utilities rent
{
	this->lastRoll = roll;
}

int Player::getLastRoll()														//Returns the last number the player rolled used for utilities rent
{
	return this->lastRoll;
}

int Player::netWorth()															//Checks to make sure the players net worth does not go below zero(their debts don't exceed their mortgage value)
{																				//If the player's networth hits zero or lower, they lose the game
	int net = this->money;
	for (Space* s : this->ownedProperties)
	{
		net += s->getMort();
	}
	return net;
}

string Player::getIcon()														//Returns the icon that the player has on the map
{
	return this->icon;
}

void Player::setIcon(string i)													//Sets the icon the player will use for the map
{
	this->icon = i;
}

void Player::tradeProperties(vector<Space*> s)									//Used in the trade function, sets the players properties array equal to the traded properties
{
	ownedProperties = s;
}