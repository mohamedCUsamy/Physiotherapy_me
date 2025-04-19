#include "EU_WaitList.h"


void EU_WaitList::insertSorted(Patient* patient)
{
    priQueue<Patient*> sortedQueue;

    Patient* currentPatient;
    int penalty;

    while (dequeue(currentPatient))
    {
        if (currentPatient->getVT() > currentPatient->getPT()) 
        {
            penalty = (currentPatient->getVT() - currentPatient->getPT()) / 2;
            currentPatient->SetPT(currentPatient->getPT() + penalty);
        }

        sortedQueue.enqueue(currentPatient, currentPatient->getPT());
  
    }

//the one who instert the new patient 
    if (patient->getVT() > patient->getPT()) 
    {
        penalty = (patient->getVT() - patient->getPT()) / 2;
        patient->SetPT(patient->getPT() + penalty);
    }

    sortedQueue.enqueue(patient, patient->getPT());

    int dummyPriority;
    while (!sortedQueue.isEmpty())
    {
        sortedQueue.dequeue(currentPatient, dummyPriority);
        enqueue(currentPatient);
    }
}



int EU_WaitList::calcTreatmentLatency()
{
    int count = 0;
    while (!isEmpty()) {
        Patient* TempPatient;
        Treatment* TempTreatment;
        dequeue(TempPatient);
        while (TempPatient->getReqTreatment().dequeue(TempTreatment))
            count += TempTreatment->getDuration();
    }
    return count;
}
