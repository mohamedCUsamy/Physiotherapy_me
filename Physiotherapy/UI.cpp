#include "UI.h"
#include <iostream>
using namespace std;

UI::UI(int num_patients, int num_U_Devices, int num_E_Devices, int num_X_Devices, float pCancel, float pReschedule,
    EU_WaitList& U_waitingList, EU_WaitList& E_waitingList, X_WaitList& X_waitingList,
    priQueue<Patient*>& inTreatment, int Croom1, int Croom2,
    LinkedQueue<Patient*>& All_Patient, LinkedQueue<Ressource*>& E_Devices,
    LinkedQueue<Ressource*>& U_Devices, LinkedQueue<Ressource*>& X_Rooms,
    priQueue<Patient*>& In_TreatmentList, ArrayStack<Patient*>& FinishedPatients,
    EarlyPList& EarlyList)
    : num_patients(num_patients), num_U_Devices(num_U_Devices), num_E_Devices(num_E_Devices), num_X_Devices(num_X_Devices),
    pCancel(pCancel), pReschedule(pReschedule),
    U_waitingList(U_waitingList), E_waitingList(E_waitingList), X_waitingList(X_waitingList),
    inTreatment(inTreatment), Croom1(Croom1), Croom2(Croom2),
    All_Patient(All_Patient), E_Devices(E_Devices), U_Devices(U_Devices), X_Rooms(X_Rooms),
    In_TreatmentList(In_TreatmentList), FinishedPatients(FinishedPatients),
    EarlyList(EarlyList)
{


}


void UI::print_info()
{

     // to print patients info
        cout << "Current time step: " << endl;
        cout << "=============== ALL List =================" << endl;
        //cout<< num_patients << "patients remaining: " << All_Patient.Print_queue() << endl; 
        cout << "=============== Waiting Lists ================= " << endl;
        cout << "E-therapy patients: " << endl;
        cout << "U-therapy patients: " << endl;
        cout << "X-therapy patients: " << endl;
        cout << "=============== Early Lists ================= " << endl;
        cout << "Patients: " << endl;
        cout << "=============== Late Lists ================= " << endl;
        cout << "=============== Avail E-device ================= " << endl;
        cout << "=============== Avail U-device ================= " << endl;
        cout << "=============== Avail X-rooms ================= " << endl;
        cout << "=============== In-treatment List ================= " << endl;
        cout << "Finished Patients: " << endl;
        cout << "Number of Patients: " << num_patients << endl;
        cout << "Number of U Devices: " << num_U_Devices << endl;
        cout << "Number of E Devices: " << num_E_Devices << endl;
        cout << "Number of X Rooms: " << num_X_Devices << endl;
        cout << "Cancellation Probability: " << pCancel << endl;
        cout << "Reschedule Probability: " << pReschedule << endl;

        cout << "\n----- Patients -----" << endl;


}
