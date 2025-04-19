#pragma once
#include "Ressource.h"


class Ressource;
class Treatment
{
	char Treatment_type;
	int duration;
	Ressource * pResource;
	int assignmentTime;


public:
	Treatment(char type,int dur);

	bool HaveRessource();

	//virtual void CanAssign();
	//virtual void MoveToWait();

	char getType();
	int getDuration();
	int getassignmenttime();



};

