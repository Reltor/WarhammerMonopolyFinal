#ifndef TAXSPACE_H
#define TAXSPACE_H

#include "Space.h"
#include <string>

class TaxSpace : public Space
{
public:
	TaxSpace(std::string);
	std::array<std::string, 11> getTitleDeed();
	virtual std::string getSpaceType();
private:
	std::string spaceType = "Tax";
};

#endif