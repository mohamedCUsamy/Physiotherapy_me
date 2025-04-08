#include "Patient.h"
using namespace std;
#include <iostream>

Patient::Patient(char* Req, int num_treatments, int* duration, int app, int arr, bool Normality,string id)
{
	SetPT(app);
	SetVT(arr);
	setType(Normality);

	for (int i = 0; i < num_treatments; i++)
	{
		Treatment* tptr = new Treatment(Req[i],duration[i]);
		ReqTreatments.enqueue(tptr);
	}

	

}

void Patient::SetPT(int PT)
{
	this->PT = PT;
}

int Patient::getPT()
{
	return PT;
}

void Patient::SetVT(int VT)
{
	this->VT = VT;

}

int Patient::getVT()
{
	return VT;
}

void Patient::setType(bool isNormal)
{
	this->isNormal = isNormal;
}

bool Patient::get_IsNormal()
{
	return isNormal;
}

LinkedQueue<Treatment*> Patient::getReqTreatment()
{
    return ReqTreatments;
}

void Patient::SetPatientStatus(Status newStatus)
{
    Patientstatus = newStatus;
}











void Patient::print_Patient_info()
{

    cout << "Patient Type: " << (isNormal ? "Normal" : "Emergency") << endl;
    cout << "Patient ID = " << ID << endl;
    cout << "PT (Processing Time): " << PT << endl;
    cout << "VT (Visit Time): " << VT << endl;

    cout << "Required Treatments:" << endl;

    LinkedQueue<Treatment*> tempQueue;
    Treatment* t;

    while (!ReqTreatments.isEmpty()) {
        ReqTreatments.dequeue(t);
        if (t) {
            cout << " - Type: " << t->getType()
                << ", Duration: " << t->getDuration() << endl;
        }
        tempQueue.enqueue(t);
    }

    while (!tempQueue.isEmpty()) {
        tempQueue.dequeue(t);
        ReqTreatments.enqueue(t);
    }
}


