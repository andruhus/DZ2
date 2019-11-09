

#include <iostream>
#include "modulsh.h"
using namespace std;

int main()
{
	int z;
	cout << "Enter the task: ";
	cin >> z;
	switch (z)
	{
	case 1: task1(); break;
	case 2: task2(); break;
	case 3: task3(); break;
	case 4: task4(); break;
	case 5: task5(); break;
	default: cout << "No such a task" << endl;
	}
}


