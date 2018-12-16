#ifndef CHANCESPACE_H
#define CHANCESPACE_H

#include "Space.h"

class ChanceSpace : public Space
{
public:
	ChanceSpace(std::string name);
	virtual std::array<std::string, 11> getTitleDeed();
private:
	std::string spaceType = "Chance";
};

#endif