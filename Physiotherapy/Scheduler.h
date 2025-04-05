#include <iostream>
using namespace std;
#include "LinkedQueue.h"
#include"Resource.h"
#include "EU_WaitList.h"
#include "X_WaitList.h"
#include "Patient.h"




class Scheduler
{
	int num_patients;

	int num_U_Devices;
	int num_E_Devices;
	int num_X_Devices;

	float pCancel;
	float pReschedule;

	

	EU_WaitList  U_List_name;
	EU_WaitList  E_List_name;
	X_WaitList  List_name;

	int Croom1;
	int Croom2;

	LinkedQueue<Patient*>  All_Patient;
	
	LinkedQueue<Resource*>E_Devices;
	LinkedQueue<Resource*>U_Devices;
	LinkedQueue<Resource*>X_Rooms;


public:

	Scheduler(string path);

	void Load_Input(string& filename); //implementation

	void Print_info();

};

