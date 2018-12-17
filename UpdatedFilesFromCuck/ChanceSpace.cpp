#include "ChanceSpace.h"

using namespace std;

ChanceSpace::ChanceSpace(string name)						//Returns the name of the space
{
	Space();
	this->name = name;
}

array<string,11> ChanceSpace::getTitleDeed()				//This lovely chunck of code displayes the information about the ChanceSpace on the right side of the screen
{
	array<string, 11> returnArray{};
	return returnArray;
}

string ChanceSpace::getSpaceType()							//Returns the type of space it is
{
	return this->spaceType;
}