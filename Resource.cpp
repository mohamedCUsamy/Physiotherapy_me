#include "Resource.h"


Resource::Resource()
{
	ResourceID = 0;
	ResourceType = "__";
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
