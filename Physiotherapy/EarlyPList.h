#pragma once
#include "PriQueue.h"
#include "Patient.h"
class EarlyPList : public priQueue<Patient*>
{
public:

	bool Reschedule(int presc, int random);

};