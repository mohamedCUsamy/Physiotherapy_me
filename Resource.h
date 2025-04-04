#include <string>
class Resource
{
private:
	int ResourceID;
	std::string ResourceType;
public:
	Resource();
	void SetResourceID(int I);
	int GetResourceId();
	void SetResourceType(std::string s);
	std::string GetResourceType();
};

