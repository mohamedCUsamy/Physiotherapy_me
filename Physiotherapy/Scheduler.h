#include <iostream>
using namespace std;
#include "LinkedQueue.h"
#include"Ressource.h"
#include "EU_WaitList.h"
#include "X_WaitList.h"
#include "Patient.h"
#include "PriQueue.h"
#include "Patient.h"
#include "UI.h"
#include "ArrayStack.h"
#include "EarlyPList.h"



class Scheduler
{
	int num_patients;

	int num_U_Devices;
	int num_E_Devices;
	int num_X_Devices;

	float pCancel;
	float pReschedule;



	string path;

	UI *pOut;

	EU_WaitList  U_waitingList;
	EU_WaitList  E_waitingList;
	X_WaitList  X_waitingList;

	priQueue<Patient*>  inTreatment;

	int Croom1;
	int Croom2;

	LinkedQueue<Patient*>  All_Patient;
	
	LinkedQueue<Ressource*>E_Devices;
	LinkedQueue<Ressource*>U_Devices;
	LinkedQueue<Ressource*>X_Rooms;


	priQueue<Patient*>In_TreatmentList;
	ArrayStack<Patient*>FinishedPatients;

	priQueue<Patient*>LatePList;

	EarlyPList EarlyPList;


public:

	Scheduler(string path);

	void Load_Input(string& filename); //implementation

	UI* get_UI_ptr();

	void AddToWait_X(); // implementation phase 2

	void AddToWait_U(); // implementation phase 2

	void AddToWait_E(); // implementation phase 2

	void Print_info();  // not in wanted form

	void Simulation();

	void testPrint();

	EU_WaitList* RandomWaitList();


};

//print with operator overloading