#include "Resource.h"


Resource::Resource(int type)
{
	ResourceID = 0;
	ResourceType = type;
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
