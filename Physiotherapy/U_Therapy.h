#pragma once
#include "Treatment.h"


class U_Therapy:public Treatment
{
public:
	U_Therapy( char type, int dur);

	void CanAssign() ;
	


};

