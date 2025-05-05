#pragma once
#include "Treatment.h"
#include "LinkedQueue.h"

class X_Therapy :public Treatment
{

private:


public:

	X_Therapy(char type, int dur);
	bool CanAssign(LinkedQueue<Resource*>& R);
};

