
#include "dz9h.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	cout << "Hello in my homework 9!" << endl;
	cout << "Choose the task (1-4)" << endl;
	cin >> t;
	switch (t)
	{
	case 1: task1(); break;
	case 2: task2(); break;
	case 3: task3(); break;
	case 4: task4(); break;
	default: cout << "there is no such a task" << endl; break;
	}
}

