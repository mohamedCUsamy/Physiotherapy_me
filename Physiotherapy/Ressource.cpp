#include "Ressource.h"


Ressource::Ressource()
{
	ResourceID = 0;
	ResourceType = "0";
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
