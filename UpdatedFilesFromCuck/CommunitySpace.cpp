#include "CommunitySpace.h"
using namespace std;

CommunitySpace::CommunitySpace(string name)						//Returns the name of the space
{
	Space();
	this->name = name;
}

string CommunitySpace::getSpaceType()							//Returns the type of space it is
{
	return this->spaceType;
}