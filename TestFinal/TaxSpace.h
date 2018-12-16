#ifndef TAXSPACE_H
#define TAXSPACE_H

#include "Space.h"

class TaxSpace : public Space
{
public:
	TaxSpace(std::string);
	std::array<std::string, 11> getTitleDeed();
private:
	std::string spaceType = "Tax";
};

#endif