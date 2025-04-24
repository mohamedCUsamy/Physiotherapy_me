#include "X_WaitList.h"

bool X_WaitList::cancel(int presc, int random, Patient*& pToBeRemoved)
{
    pToBeRemoved = nullptr; //setting it to null just to be safe
    if (random >= presc) {

        return false;
    }

    int rand1 = rand() % count; // gets a random value from 1 to patient exclusive

    LinkedQueue<Patient*> tempQ; // Temporary queue to store the patients before the patient who we want to cancel.
    Patient* selected = nullptr;// a temporary variable that holds the Patient who is cancelling


    //    for (int i = 0; i < count; i++) { // for loop to dequeue all the patients before the one we want to select
    Patient* tempPatient;
    for (int i = 0; i < count; ++i) {
        Patient* curr;
        dequeue(curr);

        if (i == rand1)
            selected = curr;
        else
            tempQ.enqueue(curr);
    }

    //if (!selected) return false; // safety check in case selected is null

    Treatment* tempTreatment;
    LinkedQueue<Treatment*> tempTreatQ;
    Treatment* lastTreatment = nullptr; // track the last treatment safely

    while (selected->getReqTreatment().dequeue(tempTreatment))
    {
        tempTreatQ.enqueue(tempTreatment);
        lastTreatment = tempTreatment;
    }

    if (lastTreatment && dynamic_cast<X_Therapy*>(lastTreatment)) {// if the patients last treatment is X

        //cancel the patient
        //move to finished list
        pToBeRemoved = selected; // to be popped in the simulation

    }
    else {
        // enqueue all treatments back
        while (!tempTreatQ.isEmpty()) {
            tempTreatQ.dequeue(tempTreatment);
            selected->getReqTreatment().enqueue(tempTreatment);
        }

        enqueue(selected);
    }

    while (!tempQ.isEmpty()) { //queueing the rest of the patients that we previously removed back to the list
        Patient* tempP;
        tempQ.dequeue(tempP);
        enqueue(tempP);
    }


    return true;
}
