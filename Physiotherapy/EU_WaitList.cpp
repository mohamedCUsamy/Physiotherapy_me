#include "EU_WaitList.h"


	void EU_WaitList::insertSorted(LinkedQueue <Patient*>&EU_list)
	{
		
		priQueue<Patient*>sortedqeue;
		
		Patient* dummyptr;
		
		int penalty;	

		while (EU_list.peek(dummyptr))
		{
			if (dummyptr->getVT() > dummyptr->getPT()) //////// ENO LATTEEEE///
			{
				penalty = (dummyptr->getVT() - dummyptr->getPT()) / 2;
				dummyptr->SetPT(dummyptr->getPT() + penalty);
			}
			EU_list.dequeue(dummyptr);
			sortedqeue.enqueue(dummyptr, dummyptr->getPT());
		}
		int dummyPT;
		while (!(sortedqeue.isEmpty()))
		{
			dummyPT = dummyptr->getPT();
			sortedqeue.dequeue(dummyptr, dummyPT);
			EU_list.enqueue(dummyptr);
		}

}

	int EU_WaitList::calcTreatmentLatency()
	{
		return 0;
	}
