#include "Treatment.h"

Treatment::Treatment(char type, int dur)
{
	Treatment_type = type;
	duration = dur;
	pResource = NULL;
	assignmentTime = 0;
}

bool Treatment::HaveResource()
{
	return pResource;
}

void Treatment::CanAssign()
{
}


char Treatment::getType()
{
	return Treatment_type;
}

int Treatment::getDuration()
{
	return duration;
}

int Treatment::getassignmenttime()
{
	return assignmentTime;
}
