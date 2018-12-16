#ifndef COMMUNITYSPACE_H
#define COMMUNITYSPACE_H
#include "Space.h"
#include <string>

class CommunitySpace : public Space
{
public:
	CommunitySpace(std::string);
	virtual std::string getSpaceType();
private:
	std::string spaceType = "Community";

};


#endif