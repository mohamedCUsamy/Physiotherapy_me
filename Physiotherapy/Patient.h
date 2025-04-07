#pragma once
#include "Treatment.h"
#include "LinkedQueue.h"
#include "enums.h"

class Patient
{
	LinkedQueue <Treatment*>  ReqTreatments;
	bool isNormal; //patient type
	int PT;
	int VT;
	Status Patientstatus;
	
public:
	Patient(char *Req, int num_treatments, int *duration,int app,int arr,bool Normality);// needs to create the treatments and initialise for each there duration gotten from input function in scheduler
	void SetPT(int PT);
	int getPT();
	void SetVT(int VT);
	int getVT();
	void setType(bool isNormal);
	bool get_IsNormal();

	void SetPatientStatus(Status newStatus);

	void print_Patient_info();
	

};

