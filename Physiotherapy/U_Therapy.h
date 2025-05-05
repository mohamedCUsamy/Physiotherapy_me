#pragma once
#include "Treatment.h"
#include "LinkedQueue.h"

class U_Therapy:public Treatment
{
public:
	U_Therapy( char type, int dur);

	bool CanAssign(LinkedQueue<Resource*>& R);



};

