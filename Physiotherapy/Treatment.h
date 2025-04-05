#pragma once
class Treatment
{
	char Treatment_type;
	int duration;

public:
	Treatment(char type,int dur);

	char getType();
	int getDuration();

};

