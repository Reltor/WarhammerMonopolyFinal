#include "TaxSpace.h"

using namespace std;

TaxSpace::TaxSpace(string name)							//Returns the name of the space
{
	Space();
	this->name = name;
}

array<string, 11> TaxSpace::getTitleDeed()				//This lovely chunck of code displayes the information about the taxSpace on the right side of the screen
{
	array<string, 11> returnArray{};
	return returnArray;
}

string TaxSpace::getSpaceType()							//Returns the type of space it is
{
	return this->spaceType;
}