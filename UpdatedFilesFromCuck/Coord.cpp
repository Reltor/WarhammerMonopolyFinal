#include "Coord.h"
Coord::Coord()						//"This is litteraly a container I used to pass an x and y coordinate at the same time" - Jared
{
	this->x = 1;
	this->y = 1;
}

Coord::Coord(int x, int y) {
	this->x = x;
	this->y = y;
}

int Coord::getX()
{
	return x;
}

int Coord::getY()
{
	return y;
}