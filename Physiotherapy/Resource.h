#pragma once
using namespace std;
#include <iostream>
#include <string>


class Resource
{
private:
	int ResourceID; // where to get this
	string ResourceType;
	int room_capacity_1;
	int room_capacity_2;
public:
	Resource(int type );
	Resource(int type , int cR1, int cR2);
	void SetResourceID(int I);
	int GetResourceId();
	void SetResourceType(string s);
	string GetResourceType();
	friend ostream& operator<<(ostream& os, Resource* pat);

};

