#include "Treatment.h"

Treatment::Treatment(char type, int dur)
{
	Treatment_type = type;
	duration = dur;

}

char Treatment::getType()
{
	return Treatment_type;
}

int Treatment::getDuration()
{
	return duration;
}
