#pragma once
#include "Treatment.h"
#include "LinkedQueue.h"

class E_Therapy: public Treatment
{


public:

	E_Therapy(char type, int dur);
	bool CanAssign(LinkedQueue<Resource*>& R);

};

