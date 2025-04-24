#pragma once
using namespace std;
#include <iostream>
#include <string>


class Resource
{
private:
	int ResourceID; // where to get this
	string ResourceType;
public:
	Resource(int type);
	void SetResourceID(int I);
	int GetResourceId();
	void SetResourceType(string s);
	string GetResourceType();
	friend ostream& operator<<(ostream& os, Resource* pat);

};

