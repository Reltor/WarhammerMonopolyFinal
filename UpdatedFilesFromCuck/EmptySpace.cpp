#include "EmptySpace.h"
#include <sstream>
#include <array>
#include <string>

using namespace std;


EmptySpace::EmptySpace(string name)									//Returns the name of the space
{
	Space();
	this->name = name;
}

array<string, 11> EmptySpace::getTitleDeed()						//This lovely chunck of code displayes the information about the EmptySpace on the right side of the screen
{
	ostringstream line1, line3, line4, line5, line6, line7, line8, line9, line10, line11;
	array<string, 11> displayArray{};
	displayArray[0] = "########################################";
	line1 << setw(40) << left << this->getName();
	displayArray[1] = line1.str();
	displayArray[2] = "########################################";


	return displayArray;
}

string EmptySpace::getSpaceType()									//Returns the type of space it is
{
	return this->spaceType;
}