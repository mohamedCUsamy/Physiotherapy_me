#include "Resource.h"


Resource::Resource(int type)
{
	ResourceID = 0;
	ResourceType = type;
}

Resource::Resource(int type, int cR1, int cR2)
{
	ResourceType = type;
	room_capacity_1 = cR1;
	room_capacity_2 = cR2;
}

void Resource::SetResourceID(int I)
{
	ResourceID = I;
}

int Resource::GetResourceId() 
{
	return ResourceID;
}


void Resource::SetResourceType(std::string s)
{
	ResourceType = s;
}

std::string Resource::GetResourceType()
{
	return ResourceType;
}

ostream& operator<<(ostream& os, Resource* pat)
{

	os << pat->GetResourceId() ;
	return os;
	
}
