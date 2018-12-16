#ifndef EMPTYSPACE_H
#define EMPTYSPACE_H

#include "Space.h"
#include <sstream>
#include <array>
#include <string>
class EmptySpace : public Space
{
public: 
	EmptySpace(std::string name);
	std::array<std::string, 11> getTitleDeed();
private:
	std::string spaceType = "Empty";
};
#endif;