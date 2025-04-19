#include "UI.h"
#include <iostream>
using namespace std;

UI::UI(int num_patients, int num_U_Devices, int num_E_Devices, int num_X_Devices, float pCancel, float pReschedule,
    EU_WaitList& U_waitingList, EU_WaitList& E_waitingList, X_WaitList& X_waitingList,
    priQueue<Patient*>& inTreatment, int Croom1, int Croom2,
    LinkedQueue<Patient*>& All_Patient, LinkedQueue<Ressource*>& E_Devices,
    LinkedQueue<Ressource*>& U_Devices, LinkedQueue<Ressource*>& X_Rooms,
    priQueue<Patient*>& In_TreatmentList, ArrayStack<Patient*>& FinishedPatients,
    EarlyPList& EarlyList, priQueue<Patient*>& LateList)
    :num_patients(num_patients), num_U_Devices(num_U_Devices), num_E_Devices(num_E_Devices), num_X_Devices(num_X_Devices),
    pCancel(pCancel), pReschedule(pReschedule),
    U_waitingList(U_waitingList), E_waitingList(E_waitingList), X_waitingList(X_waitingList),
    inTreatment(inTreatment), Croom1(Croom1), Croom2(Croom2),
    All_Patient(All_Patient), E_Devices(E_Devices), U_Devices(U_Devices), X_Rooms(X_Rooms),
    In_TreatmentList(In_TreatmentList), FinishedPatients(FinishedPatients),
    EarlyList(EarlyList), LateList(LateList)
{


}


// this function was added to print the finished list instead of the build in one in stack but Okay working good
void UI::printFinishedListID() {
    ArrayStack<Patient*> TempStack; 
    Patient* TempPatient = nullptr;

    while (!FinishedPatients.isEmpty()) {
        FinishedPatients.pop(TempPatient);

        if (TempPatient != nullptr) {
            cout << TempPatient->getId() << " ";
        }

        TempStack.push(TempPatient); 
    }

    while (!TempStack.isEmpty()) {
        TempStack.pop(TempPatient);
        FinishedPatients.push(TempPatient);
    }

    cout << endl;
}




void UI::print_info(int timestep)
{

     // to print patients info
        cout << "Current time step: " << timestep<<endl;
        cout << "=============== ALL List =================" << endl;
        cout << All_Patient.getCount() << "  patients remaining:  ";
        All_Patient.print();
        cout<< endl;
        cout << "=============== Waiting Lists ================= " << endl;
        cout << E_waitingList.getCount() << "  E-therapy patients: ";
        E_waitingList.print();
        cout << endl;
        cout << U_waitingList.getCount() << "  U-therapy patients: ";
        U_waitingList.print();
        cout << endl;
        cout << X_waitingList.getCount() << "  X-therapy patients: ";
        X_waitingList.print();
        
        cout << endl;
        cout << "=============== Early Lists ================= " << endl;
        cout << EarlyList.getCount() << " Patients: ";
        EarlyList.print();
        cout << endl;

        
        cout << "=============== Late Lists ================= " << endl;
        cout << LateList.getCount() <<  " Patients: ";
        LateList.print();
        cout << endl;
        cout << "=============== Avail E-device ================= " << endl;

        cout << E_Devices.getCount() << " Electro devices ";
        E_Devices.print();
        cout << endl;

        cout << "=============== Avail U-device ================= " << endl;
        cout << U_Devices.getCount() << " Ultra devices ";
        cout << endl;
        cout << "=============== Avail X-rooms ================= " << endl;
        cout << X_Rooms.getCount() << " rooms ";
        X_Rooms.print();
        cout << endl;
        cout << "=============== In-treatment List ================= " << endl;
        cout << In_TreatmentList.getCount() << " ==> ";
        In_TreatmentList.print();
        cout << endl;

        cout << "Finished Patients: " << endl;
        cout << FinishedPatients.getCount() << " Patients: ";
        printFinishedListID();
        cout << endl;

        cout << "Number of Patients: " << num_patients << endl;
        cout << "Number of U Devices: " << num_U_Devices << endl;
        cout << "Number of E Devices: " << num_E_Devices << endl;
        cout << "Number of X Rooms: " << num_X_Devices << endl;
        cout << "Cancellation Probability: " << pCancel << endl;
        cout << "Reschedule Probability: " << pReschedule << endl;

        cout << "----- Patients -----" << endl;


}
