#pragma once
#include "Patient.h"
#include "LinkedQueue.h"
#include "PriQueue.h"
class EU_WaitList : public LinkedQueue<Patient*>
{

public:
	
	 
	void insertSorted(LinkedQueue <Patient*>& EU_list);
	
	int calcTreatmentLatency();

};

