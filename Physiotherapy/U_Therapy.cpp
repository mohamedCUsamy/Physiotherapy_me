#include "U_Therapy.h"
using namespace std;
#include <iostream>

U_Therapy::U_Therapy(char type, int dur): Treatment(type,  dur)
{

}

bool U_Therapy::CanAssign(LinkedQueue<Resource*> &R)
{
	if (R.isEmpty() && !HaveResource() )
		return false;
	return true;
}