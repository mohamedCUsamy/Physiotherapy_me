#include "Ressource.h"


Ressource::Ressource(int type)
{
	ResourceID = 0;
	ResourceType = type;
}

void Ressource::SetResourceID(int I)
{
	ResourceID = I;
}

int Ressource::GetResourceId() 
{
	return ResourceID;
}


void Ressource::SetResourceType(std::string s)
{
	ResourceType = s;
}

std::string Ressource::GetResourceType()
{
	return ResourceType;
}
