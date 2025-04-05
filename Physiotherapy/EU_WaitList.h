#pragma once
#include "Patient.h"
#include "LinkedQueue.h"

class EU_WaitList : public LinkedQueue<Patient*>
{

public:
	
	
	void insertSorted(); // implement
	
	int calcTreatmentLatency(); // implement

};

