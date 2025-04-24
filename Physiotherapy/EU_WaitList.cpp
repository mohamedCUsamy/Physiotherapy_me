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

int EU_WaitList::calcTreatmentLatency(char type)
{
    int count = 0;
    int uCount;
    int eCount;
    int xCount;
    Patient* TempPatient;
    Treatment* TempTreatment;
    LinkedQueue<Patient*> tempQ;
    while (!isEmpty()) {
 
        dequeue(TempPatient);

        while (TempPatient->getReqTreatment().dequeue(TempTreatment)) {
            if (dynamic_cast<U_Therapy*>(TempTreatment))
                uCount = TempTreatment->getDuration();
            else if (dynamic_cast<X_Therapy*>(TempTreatment))
                xCount = TempTreatment->getDuration();
            else if (dynamic_cast<E_Therapy*>(TempTreatment))
                eCount = TempTreatment->getDuration();

            tempQ.enqueue(TempPatient);
        }

    }

    while (!tempQ.isEmpty()) {
        tempQ.dequeue(TempPatient);
        enqueue(TempPatient);
    }

    return count;
}
