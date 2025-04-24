#pragma once
#include "Patient.h"
#include "LinkedQueue.h"
#include "PriQueue.h"
#include "U_Therapy.h"
#include "X_Therapy.h"
#include "E_Therapy.h"

class EU_WaitList : public LinkedQueue<Patient*>
{

public:
	
	 
	void insertSorted(Patient* patient);
	
	int calcTreatmentLatency(char type);

};

