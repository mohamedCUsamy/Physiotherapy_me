#include "X_WaitList.h"
#include "enums.h"

bool X_WaitList::cancel(int presc, int random, Patient*& pToBeRemoved)
{
    pToBeRemoved = nullptr; //setting it to null just to be safe
    if (random >= presc) {//presc: probability that a patient reschedules, random is a random number generated in the simulation

        return false;
    }

    int rand1 = rand() % count; // gets a random value from 1 to patient exclusive

    LinkedQueue<Patient*> tempQ; // Temporary queue to store the patients before the patient who we want to cancel.
    Patient* selected;// a temporary variable that holds the Patient who is cancelling


    //    for (int i = 0; i < count; i++) { // for loop to dequeue all the patients before the one we want to select
    Patient* tempPatient;
    while (dequeue(tempPatient))
    {
        tempQ.enqueue(tempPatient);

    }

    dequeue(selected); // dequeueing the selected patient and storing in selected variable

    Treatment* tempTreatment;
    LinkedQueue<Treatment*> tempTreatQ;

    while (selected->getReqTreatment().dequeue(tempTreatment))
    {
        tempTreatQ.enqueue(tempTreatment);
    }

    if (tempTreatment->getType() == 'X') {// if the patients last treatment is X

        //cancel the patient
        //move to finished list
        pToBeRemoved = selected; // to be popped in the simulation
        selected->SetPatientStatus(Status::FNSH);//changing the satus *****dk if this is totally right 

    }
    else {
        selected->getReqTreatment().enqueue(tempTreatment);// requeue the patient like nth happened
        enqueue(selected);
    }

    while (!tempTreatQ.isEmpty()) {

        tempTreatQ.dequeue(tempTreatment);
        selected->getReqTreatment().enqueue(tempTreatment);

    }

    while (!tempQ.isEmpty()) { //queueing the rest of the patients that we previously removed back to the list
        Patient* tempP;
        tempQ.dequeue(tempP);
        enqueue(tempP);
    }



    // ps there could be an edge case here related to teh selected pointer being null so i think i need to check that


    return true;
}