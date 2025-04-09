#include "Scheduler.h"
#include <fstream>
#include "UI.h"
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




    // intialize all before this function 
    Load_Input(path);

    cout << num_patients;

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

UI* Scheduler::get_UI_ptr()
{
    return pOut;
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
