#ifndef COMMUNITYSPACE_H
#define COMMUNITYSPACE_H
#include "Space.h"

class CommunitySpace : public Space
{
public:
	CommunitySpace(std::string);
private:
	std::string spaceType = "Community";

};


#endif