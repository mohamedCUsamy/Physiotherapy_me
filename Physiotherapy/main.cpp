#include <iostream>
using namespace std;
#include "Scheduler.h"

int main() {
	string path= "test.txt";
	Scheduler s1(path);
	s1.get_UI_ptr()->print_info(87);
}