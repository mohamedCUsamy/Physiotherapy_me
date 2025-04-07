#include "EarlyPList.h"
#include <cstdlib>  
#include <ctime> 

bool EarlyPList::Reschedule(Patient* patient, int NewPT, int presc, int random, int Pnum)
{

    if (NewPT < patient->getPT()) {
        return false;
    }

    if (presc > random) {

        int rand1 = rand() % (Pnum + 1);

        LinkedQueue<Patient*> tempQ;
        Patient* selected = nullptr;



        while (isEmpty()) {

            int tempPrio;
            Patient* tempPatient;

            dequeue(tempPatient, tempPrio);



            if (!selected) {
                selected = tempPatient;
            }
            tempQ.enqueue(tempPatient);

        }

        int rand2 = rand() % (101 - patient->getPT()) + patient->getPT();
        selected->SetPT(rand2);
        enqueue(selected, rand2);


        while (!tempQ.isEmpty()) {
            Patient* tempP;
            int tempPT;
            tempQ.dequeue(tempP);
            enqueue(tempP, tempP->getPT());
        }
    }


    return true;
}