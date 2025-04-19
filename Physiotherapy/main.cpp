#include <iostream>
using namespace std;
#include "Scheduler.h"

int main() {
	string path= "test_case.txt";
	Scheduler s1(path);

	s1.Simulation();
}