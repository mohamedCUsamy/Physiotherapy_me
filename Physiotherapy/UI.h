#pragma once

#include <iostream>
using namespace std;
#include "LinkedQueue.h"
#include"Resource.h"
#include "EU_WaitList.h"
#include "X_WaitList.h"
#include "Patient.h"
#include "PriQueue.h"
#include "Patient.h"
#include "ArrayStack.h"
#include "EarlyPList.h"

class UI
{


private:

        // Store references to all the lists
        int num_patients;
        int num_U_Devices;
        int num_E_Devices;
        int num_X_Devices;
        float pCancel;
        float pReschedule;

        EU_WaitList& U_waitingList;
        EU_WaitList& E_waitingList;
        X_WaitList& X_waitingList;
        priQueue<Patient*>& inTreatment;
        int Croom1;
        int Croom2;
        LinkedQueue<Patient*>& All_Patient;
        LinkedQueue<Resource*>& E_Devices;
        LinkedQueue<Resource*>& U_Devices;
        LinkedQueue<Resource*>& X_Rooms;
        priQueue<Patient*>& In_TreatmentList;
        ArrayStack<Patient*>& FinishedPatients;
        EarlyPList& EarlyList;
        priQueue<Patient*>& LateList;


public:     // Constructor taking all the required parameters
        UI(
            int num_patients,
            int num_U_Devices,
            int num_E_Devices,
            int num_X_Devices,
            float pCancel,
            float pReschedule,
            EU_WaitList& U_waitingList,
            EU_WaitList& E_waitingList,
            X_WaitList& X_waitingList,
            priQueue<Patient*>& inTreatment,
            int Croom1,
            int Croom2,
            LinkedQueue<Patient*>& All_Patient,
            LinkedQueue<Resource*>& E_Devices,
            LinkedQueue<Resource*>& U_Devices,
            LinkedQueue<Resource*>& X_Rooms,
            priQueue<Patient*>& In_TreatmentList,
            ArrayStack<Patient*>& FinishedPatients,
            EarlyPList& EarlyList, 
            priQueue<Patient*>& LateList

        );


        void printFinishedListID();

        void print_info(int timestep);


};

