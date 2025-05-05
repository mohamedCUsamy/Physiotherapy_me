#include "X_Therapy.h"

X_Therapy::X_Therapy(char type, int dur):Treatment(type, dur)
{

}

bool X_Therapy::CanAssign(LinkedQueue<Resource*>& R)
{
	if (R.isEmpty() && !HaveResource())
		return false;
	return true;
}


