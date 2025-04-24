#include "Patient.h"
using namespace std;
#include <iostream>
#include <string>
#include "U_Therapy.h"
#include "E_Therapy.h"
#include "X_Therapy.h"



Patient::Patient(char* Req, int num_treatments, int* duration, int app, int arr, bool Normality, string id)
{
    SetPT(app);
    SetVT(arr);
    setType(Normality);
    ID = id;


    Treatment* tptr;
    for (int i = 0; i < num_treatments; i++)
    {
        if (Req[i] == 'U') {
            tptr = new U_Therapy(Req[i], 1);
            ReqTreatments.enqueue(tptr);
        }
        else if (Req[i] == 'E') {
            tptr = new E_Therapy(Req[i], 1);
            ReqTreatments.enqueue(tptr);
        }
        else if (Req[i] == 'X'){
            tptr = new X_Therapy(Req[i], 1);
            ReqTreatments.enqueue(tptr);
        }
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

string Patient::getId()
{
    return ID;
}

Status Patient::getPatientStatus()
{
    return Status();
}

bool Patient::AddReqTreatments(Treatment* reqTreatment)
{

    return ReqTreatments.enqueue(reqTreatment);
    
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

ostream& operator<<(ostream& os, Patient* pat)
{

    os << pat->getId() ;
    return os;
}

ostream& operator<<(ostream& os, Patient& pat) {
    os << pat.getId();
    return os;
}
