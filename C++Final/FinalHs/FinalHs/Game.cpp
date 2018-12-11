#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <random>
#include <array>
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
//When we instantiate the classes, we should make pointers to the objects for poly morphism so that we can make the whole board an array of spaces

void Game::landOnTile()
{
	Player p = Player();
	Space s = Space();
	if (s.owned == true)
	{
		if (s.owner != nullptr)
		{
			p.rent(s.getRent);
			s.owner.getMoney(s.getRent);
		}
		else
		{
			p.rent(s.getRent);
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
