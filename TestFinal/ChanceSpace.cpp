#include "ChanceSpace.h"

using namespace std;

ChanceSpace::ChanceSpace(string name)
{
	Space();
	this->name = name;
}

array<string,11> ChanceSpace::getTitleDeed()
{
	array<string, 11> returnArray{};
	return returnArray;
}

string ChanceSpace::getSpaceType()
{
	return this->spaceType;
}