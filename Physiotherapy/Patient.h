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
	string ID;
	Status Patientstatus; 
	
public:
	Patient(char *Req, int num_treatments, int *duration,int app,int arr,bool Normality,string id);// needs to create the treatments and initialise for each there duration gotten from input function in scheduler
	void SetPT(int PT);
	int getPT();
	void SetVT(int VT);
	int getVT();
	void setType(bool isNormal);
	bool get_IsNormal();
	string getId();

	bool AddReqTreatments(Treatment* reqTreatment);

	LinkedQueue <Treatment*> getReqTreatment();
	void SetPatientStatus(Status newStatus);

	friend ostream& operator<<(ostream& os, Patient* pat);

	void print_Patient_info();
	

};

