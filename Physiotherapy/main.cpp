#include <iostream>
using namespace std;
#include "Scheduler.h"

int main() {
	string path= "C:\\Users\\user\\Desktop\\test.txt";
	Scheduler s1(path);
	s1.Print_info();
}