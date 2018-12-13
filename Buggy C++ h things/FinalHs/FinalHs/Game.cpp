#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
#include <random>
#include "Space.h"
#include "Game.h"
#include "Utilities.h"
#include "Properties.h"
#include "GTJTile.h"
#include "RailRoad.h"



bool Game::move()
{
	return false;
}

Properties * Game::buyFromBank()
{
	return nullptr;
}
int Game::rollDie()
{

	return 0;
}
//When we instantiate the classes, we should make pointers to the objects for poly morphism so that we can make the whole board an array of spaces

void Game::landOnTile()
{
	Player p = Player();
	Space s = Space();
	if (s.getOwned == true)
	{
		if (s.getOwner != nullptr)
		{
			p.payRent(s.getRent);
			s.getOwner.getMoney(s.getRent);
		}
		else
		{
			p.payRent(s.getRent);
		}
	}
	else
	{
		//offer to buy
		//if yes
			//do that whole thing
		//else
			//auction and do that whole thing
	}
}
