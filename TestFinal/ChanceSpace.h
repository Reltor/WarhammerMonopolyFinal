#ifndef CHANCESPACE_H
#define CHANCESPACE_H

#include "Space.h"
#include <string>

class ChanceSpace : public Space
{
public:
	ChanceSpace(std::string name);
	virtual std::array<std::string, 11> getTitleDeed();
	virtual std::string getSpaceType();
private:
	std::string spaceType = "Chance";
};

#endif