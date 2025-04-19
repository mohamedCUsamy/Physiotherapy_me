#include "EarlyPList.h"
#include <cstdlib>  
#include <ctime> 

bool EarlyPList::Reschedule(int presc, int random, Patient*& FinishedPatient)
{

    //if (random >= presc) {//presc: probability that a patient reschedules, random is a random number generated in the simulation

    //    return false;
    //}
    int rand1=0;
    if (isEmpty())
        return false;

    rand1 = (rand() % count) + 1; // gets a random value from 1 to the number of patients


    LinkedQueue<Patient*> tempQ; // Temporary queue to store the patients before the patient whom we want to resched.
    Patient* selected = nullptr;// a temporary variable that holds the Patient whom is rescheduling
    int tempPrio;//place-holder variable just recieves the priority of current dequeued and does nothing with it

    int count1 = 0;

    while(!isEmpty()){ // for loop to dequeue all the patients before the one we want to select
        count1++;

        Patient* tempPatient;

        dequeue(tempPatient, tempPrio);
        tempQ.enqueue(tempPatient);

        if (count == rand1)
            selected = tempPatient;

    }

    FinishedPatient = selected;
    if (!selected)
        return false;

         int rand2 = rand() % (101 - selected->getPT()) + selected->getPT();// generating a random appointment time

    // that is later than the PT of selected patient 
    //
    selected->SetPT(rand2); // setting the new PT for the patient
    enqueue(selected, rand2); // enqeuueing patient in original priority queue



    while (!tempQ.isEmpty()) { //queueing the rest of the patients that we previously removed back to the list
        Patient* tempP;
        int tempPT;
        tempQ.dequeue(tempP);
        enqueue(tempP, tempP->getPT());
    }

    return true; // if we were able to change the PT function returns true
}