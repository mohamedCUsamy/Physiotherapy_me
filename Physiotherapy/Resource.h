using namespace std;
#include <iostream>
#include <string>


class Resource
{
private:
	int ResourceID; // where to get this
	string ResourceType;
public:
	Resource();
	void SetResourceID(int I);
	int GetResourceId();
	void SetResourceType(string s);
	string GetResourceType();
};

