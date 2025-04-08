#include "Scheduler.h"
#include <fstream>
#include "UI.h"
#include <iostream>
using namespace std;


Scheduler::Scheduler(string path)
{

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
        this->EarlyPList
    );

    pOut = OUTPUT;




    for (int i = 0; i < num_E_Devices; i++)
    {
        Ressource *Rptr = new Ressource('E');
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
    //all devices are in the queue

    num_U_Devices = 0;
    num_E_Devices = 0;
    num_X_Devices = 0;




    // intialize all before this function 
    Load_Input(path);


}

void Scheduler::Load_Input(string& filename)
{

        ifstream file(filename);
        if (!file) { cerr << "Error opening file!\n"; return; }

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
            char type; int VT, PT;
            file >> type >> PT >> VT >> numTreatments;

            if (i == 0) {
                treatments = new char[numTreatments]; // creat array once
                duration = new int[numTreatments];
            }
            for (int i = 0; i < numTreatments; i++)
            {
                treatments[i] = ' ';
                duration[i] = 0;

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

void Scheduler::Print_info()
{
    // to print patients info
    cout << "===== Scheduler Info =====" << endl;
    cout << "Number of Patients: " << num_patients << endl;
    cout << "Number of U Devices: " << num_U_Devices << endl;
    cout << "Number of E Devices: " << num_E_Devices << endl;
    cout << "Number of X Rooms: " << num_X_Devices << endl;
    cout << "Cancellation Probability: " << pCancel << endl;
    cout << "Reschedule Probability: " << pReschedule << endl;

    cout << "\n----- Patients -----" << endl;

    LinkedQueue<Patient*> tempQueue;
    Patient* p;

    while (!All_Patient.isEmpty()) {
        All_Patient.dequeue(p);
        if (p) {
            p->print_Patient_info();
            cout << "---------------------" << endl;
        }
        tempQueue.enqueue(p);
    }

    // Restore original queue
    while (!tempQueue.isEmpty()) {
        tempQueue.dequeue(p);
        All_Patient.enqueue(p);
    }

}


void Scheduler::Simulation()
{

    while (FinishedPatients.getCount()< num_patients) {
        //      part a;
        Load_Input(path);

        int timestep = 1;

        for (int i = 0;i < num_patients;i++) {

            Patient* TempPatient;
            All_Patient.dequeue(TempPatient);
            All_Patient.enqueue(TempPatient);

            if (TempPatient->getVT() == timestep) {

                if (TempPatient->getVT() > TempPatient->getPT()) {

                    EarlyPList.enqueue(TempPatient, TempPatient->getPT());

                }
                else if (TempPatient->getVT() < TempPatient->getPT()) {

                    int penalty = (TempPatient->getPT() - TempPatient->getVT()) / 2;
                    LatePList.enqueue(TempPatient, TempPatient->getVT() + penalty);

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

            }

        }

        //part b;

        int X = rand() % 100;

        Patient* TempPatient;
        int PlaceHolder;
        if (X < 10) {

            EarlyPList.dequeue(TempPatient, PlaceHolder);
            RandomWaitList().enqueue(TempPatient);

        } if (X >= 10 && X < 20) {

            LatePList.dequeue(TempPatient, PlaceHolder);

            int penalty = (TempPatient->getPT() - TempPatient->getVT()) / 2;

            int newPT = TempPatient->getPT() + penalty;

            TempPatient->SetPT(newPT);

            RandomWaitList().enqueue(TempPatient);

        } if (X >= 20 && X < 40) {

            Treatment* TempTreatment;

            RandomWaitList().dequeue(TempPatient);
            TempPatient->getReqTreatment().peek(TempTreatment);
            inTreatment.enqueue(TempPatient, TempTreatment->getassignemntTime() + TempTreatment->getDuration());

            RandomWaitList().dequeue(TempPatient);
            TempPatient->getReqTreatment().peek(TempTreatment);
            inTreatment.enqueue(TempPatient, TempTreatment->getassignemntTime() + TempTreatment->getDuration());




        } if (X >= 40 && X < 50) {

            inTreatment.dequeue(TempPatient, PlaceHolder);

            RandomWaitList().enqueue(TempPatient);

        } if (X >= 50 && X < 60) {

            inTreatment.dequeue(TempPatient, PlaceHolder);
            FinishedPatients.push(TempPatient);

        } if (X >= 60 && X < 70) {
            int random = rand() % X_waitingList.getCount();
            Patient* TempPatient;
            X_waitingList.cancel(pCancel, random, TempPatient);
            FinishedPatients.push(TempPatient);

        }if (X >= 70 && X < 80) {

            int random = rand() % X_waitingList.getCount();
            Patient* TempPatient;
            EarlyPList.Reschedule(pReschedule, random);
            FinishedPatients.push(TempPatient);

        }



        timestep++;
    }



}

EU_WaitList Scheduler::RandomWaitList()
{
    int random = rand() % 3;

    if (random == 0) {
        return U_waitingList;
    }
    else if (random == 1) {
        return E_waitingList;
    }
    else if (random == 2) {
        return X_waitingList;
    }
}