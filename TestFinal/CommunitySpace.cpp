#include "CommunitySpace.h"
using namespace std;

CommunitySpace::CommunitySpace(string name)
{
	Space();
	this->name = name;
}

string CommunitySpace::getSpaceType()
{
	return this->spaceType;
}