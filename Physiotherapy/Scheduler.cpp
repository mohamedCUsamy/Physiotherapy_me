#include "Scheduler.h"
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;


Scheduler::Scheduler(string path)
{

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
            Ppatient = new Patient(treatments, numTreatments, duration,PT, VT, type);
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
