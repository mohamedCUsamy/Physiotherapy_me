#pragma once
using namespace std;
#include <iostream>
#include <string>


class Ressource
{
private:
	int ResourceID; // where to get this
	string ResourceType;
public:
	Ressource(int type);
	void SetResourceID(int I);
	int GetResourceId();
	void SetResourceType(string s);
	string GetResourceType();
};

