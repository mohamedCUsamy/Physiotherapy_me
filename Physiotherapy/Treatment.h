#pragma once
#include "Resource.h"

class Treatment
{
	char Treatment_type;
	int duration;
	Resource* pResource;
	int assignmentTime;


public:
	Treatment(char type,int dur);

	bool HaveRessource();

	virtual void CanAssign();
	virtual void MoveToWait();

	char getType();
	int getDuration();



};

