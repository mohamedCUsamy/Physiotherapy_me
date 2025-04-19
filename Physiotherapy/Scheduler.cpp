#include "Scheduler.h"
#include <fstream>
#include "UI.h"
#include <random>
#include <cstdlib>  
#include <ctime>
#include <iostream>
using namespace std;


Scheduler::Scheduler(string path)
{
            
    num_patients = 0;
    num_U_Devices = 0;
    num_E_Devices = 0;
    num_X_Devices = 0;
    pCancel = 0;
    pReschedule = 0;
    Croom1 = 0;
    Croom2 = 0;

    Load_Input(path);
    for (int i = 0; i < num_E_Devices; i++)
    {
        Ressource* Rptr = new Ressource('E');
        E_Devices.enqueue(Rptr);
    }

    for (int i = 0; i < num_U_Devices; i++)
    {
        Ressource* Rptr = new Ressource('U');
        U_Devices.enqueue(Rptr);
    }

    for (int i = 0; i < num_X_Devices; i++)
    {
        Ressource* Rptr = new Ressource('X');
        X_Rooms.enqueue(Rptr);
    }


    // Inside your Scheduler class (probably in constructor or initialization function)
    UI* OUTPUT = new UI(
        this->num_patients,    // or just num_patients if local variable
        this->num_U_Devices,
        this->num_E_Devices,
        this->num_X_Devices,
        this->pCancel,
        this->pReschedule,
        this->U_waitingList,   // reference to member variable
        this->E_waitingList,
        this->X_waitingList,
        this->inTreatment,
        this->Croom1,
        this->Croom2,
        this->All_Patient,
        this->E_Devices,
        this->U_Devices,
        this->X_Rooms,
        this->In_TreatmentList,
        this->FinishedPatients,
        this->EarlyPList,
        this->LatePList
    );


    pOut = OUTPUT;


    srand(time(0));

    
    //all devices are in the queue




    // intialize all before this function 


}

void Scheduler::Load_Input(string& filename)
{

        ifstream file(filename);

        if (!file) {
            cout << "Error opening file!" << endl; 
            return;
        }



        int E, U, X;
       //cout << "Devices: E=" << E << ", U=" << U << ", X=" << X << "\n";
         file >> E;
         num_E_Devices = E;
         file >> U;
         num_U_Devices = U; 
         file >> X;
         num_X_Devices = X;

        int room1_capacity, room2_capacity;
        file >> room1_capacity;
        // cout << "Gym Rooms: " << room1_capacity << " and " << room2_capacity << "\n";
        Croom1 = room1_capacity;
        
        file >> room2_capacity;
        Croom2 = room2_capacity;

        int pc, pr;
        file >> pc >> pr;
        double Pcancel = pc / 100.0;
        double Presc = pr / 100.0;
        pCancel = Pcancel;
        pReschedule = Presc;


        int numPatients;
        file >> numPatients;
        //cout << "Patients: " << numPatients << "\n";
        num_patients=numPatients;

        int numTreatments;         //5  6  7
        int* duration = nullptr;   //U X E
        char* treatments = NULL;  // U 5 X 6 E 7

        

        for (int i = 0; i < numPatients; i++) {
            char type; 
            int VT;
            int PT;
            file >> type >> PT >> VT >> numTreatments;

            if (i == 0) {
                treatments = new char[numTreatments]; // creat array once
                duration = new int[numTreatments];
            }
            for (int j = 0; j < numTreatments; j++)
            {
                treatments[j] = ' ';
                duration[j] = 0;

            }




            for (int j = 0; j < numTreatments; j++) {
                char the_input;
                int time;
                file >> the_input >> time;
                treatments[j] = the_input;
                duration[j] = time;
                // assume we put it with the order of input
                //two parrallel arrays
            }

            //create patient and add for them the information for each here + add it to the All patient list
            Patient* Ppatient;

            string id="P" + to_string(i)+ "_" + to_string(VT) ;

            Ppatient = new Patient(treatments, numTreatments, duration,PT, VT, type,id);
            All_Patient.enqueue(Ppatient);

        }
        file.close();
    
       




}

UI* Scheduler::get_UI_ptr()
{
    return pOut;
}



void Scheduler::Simulation()
{

    int timestep = 0;

    while (FinishedPatients.getCount() < num_patients){


        Patient* TempPatient;
        All_Patient.peek(TempPatient);
            


        while (TempPatient->getVT() == timestep) {


            All_Patient.dequeue(TempPatient);

            if (TempPatient->getVT() < TempPatient->getPT()) {

                EarlyPList.enqueue(TempPatient, TempPatient->getPT());

            }
            else if (TempPatient->getVT() > TempPatient->getPT()) {

                LatePList.enqueue(TempPatient, TempPatient->getPT());


            }
            else {//here generate random number N 


                int N = rand() % 100;

                if (N < 33) {

                    E_waitingList.enqueue(TempPatient);

                }
                else if (N >= 33 && N < 66) {

                    U_waitingList.enqueue(TempPatient);


                }
                else {
                    X_waitingList.enqueue(TempPatient);

                }
            }


            All_Patient.peek(TempPatient);
            if (TempPatient->getVT() != timestep || All_Patient.isEmpty()) {
                break;
            }


        }



        //part b;
        
        int X = rand() % 100;
        int PlaceHolder;
        if (X < 10) {
            EU_WaitList* tempWaitList = RandomWaitList();

            if (!EarlyPList.isEmpty()) {
                Patient* TempPatient;
                EarlyPList.dequeue(TempPatient, PlaceHolder);
                tempWaitList->enqueue(TempPatient);
            }

        } if (X >= 10 && X < 20) {

            Patient* TempPatient = nullptr;

            if (!LatePList.isEmpty()) {
                LatePList.dequeue(TempPatient, PlaceHolder);
                EU_WaitList* tempWaitList;
                tempWaitList = RandomWaitList();

                int penalty = (TempPatient->getVT() - TempPatient->getPT()) / 2;

                int newPT = TempPatient->getPT() + penalty;

                TempPatient->SetPT(newPT);

                tempWaitList->enqueue(TempPatient);
            }

        } if (X >= 20 && X < 40) {

            Treatment* TempTreatment;
            Patient* TempPatient;

            EU_WaitList* TempWaitList = RandomWaitList();

            if (!X_waitingList.isEmpty()) {
                X_waitingList.dequeue(TempPatient);
                TempPatient->getReqTreatment().peek(TempTreatment);

                In_TreatmentList.enqueue(TempPatient, TempTreatment->getassignmenttime() + TempTreatment->getDuration());
            }
            if(!TempWaitList->isEmpty()){

                TempWaitList->dequeue(TempPatient);
                TempPatient->getReqTreatment().peek(TempTreatment);
                In_TreatmentList.enqueue(TempPatient, TempTreatment->getassignmenttime() + TempTreatment->getDuration());
            }


        } if (X >= 40 && X < 50) {
            Patient* TempPatient;
            if (!In_TreatmentList.isEmpty()) {
                In_TreatmentList.dequeue(TempPatient, PlaceHolder);
                
                EU_WaitList* tempwaitlist = RandomWaitList();
                tempwaitlist->insertSorted(TempPatient);
            }
        } if (X >= 50 && X < 60) {
            Patient* TempPatient;
            if (!In_TreatmentList.isEmpty()) {
                In_TreatmentList.dequeue(TempPatient, PlaceHolder);
                FinishedPatients.push(TempPatient);
            }
        } if (X >= 60 && X < 70) {

            Patient* TempPatient;

            //if (!X_waitingList.isEmpty()) {
            //    int random = rand() % X_waitingList.getCount();
            //     X_waitingList.cancel(pCancel, random, TempPatient);
            //    FinishedPatients.push(TempPatient);

            //}
        }
        if (X >= 70 && X < 80) {
            if (!X_waitingList.isEmpty() && !EarlyPList.isEmpty()) {
                int random = rand() % X_waitingList.getCount();


                Patient* TempPatient;
                EarlyPList.Reschedule(pReschedule, random, TempPatient);
                FinishedPatients.push(TempPatient);

            }
        }
       

        pOut->print_info(timestep);
        cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;cout << endl;
        timestep++;

    }
  

}


EU_WaitList* Scheduler::RandomWaitList()
{
    int N = rand() % 100;

    if (N < 33) {
        return &U_waitingList;
    }
    else if (N >= 33 && N < 66) {
        return &E_waitingList;
    }
    else {
        return &X_waitingList;
    }
}


