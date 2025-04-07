#pragma once
#include "PriQueue.h"
#include "Patient.h"
class EarlyPList : public priQueue<Patient*>
{
private:



public:

	bool Reschedule(Patient* patient, int NewPT, int presc, int random, int Pnum);

};