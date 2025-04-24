#pragma once
#include "Resource.h"


class Resource;
class Treatment
{
	char Treatment_type;
	int duration;
	Resource * pResource;
	int assignmentTime;


public:
	Treatment(char type,int dur);

	bool HaveResource();

	virtual void CanAssign();
	//virtual void MoveToWait();

	char getType();
	int getDuration();
	int getassignmenttime();



};

