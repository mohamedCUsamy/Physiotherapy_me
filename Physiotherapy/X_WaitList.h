#pragma once
#include "EU_Waitlist.h"
#include "Patient.h"
#include "X_Therapy.h"

class X_WaitList : public EU_WaitList
{


public:
	bool cancel(int presc, int random, Patient*& pToBeRemoved);
	//to implement
};

