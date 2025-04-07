#include "Treatment.h"

Treatment::Treatment(char type, int dur)
{
	Treatment_type = type;
	duration = dur;
	pResource = NULL;
}

bool Treatment::HaveRessource()
{
	return (pResource);
}


char Treatment::getType()
{
	return Treatment_type;
}

int Treatment::getDuration()
{
	return duration;
}
