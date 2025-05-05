#include "E_Therapy.h"

E_Therapy::E_Therapy(char type, int dur) : Treatment(type, dur)
{
}

bool E_Therapy::CanAssign(LinkedQueue<Resource*>& R)
{
	if (R.isEmpty() && !HaveResource())
		return false;
	return true;
}
