#include <math.h>

#include <iostream>
#include <vector>
#include "dz6h.h"
using namespace std;

void menu()
{
	char a;
	int k;
	cout << "Enter your block of tasks: ";
	cin >> a;
	if (a == 's') {
		cout << "Enter your task: ";
		cin >> k;
		switch (k) {
		case 1: task1(); break;
		case 2: task2(); break;
		case 3: task3(); break;
		case 4: task4(); break;
		default: cout << "there is no task with such a number" << endl; menu();
		}
	}
	else if (a == 'p')
	{
		cout << "Enter your task: ";
		cin >> k;
		switch (k) {
		case 1: task5(); break;
		case 2: task6(); break;
		case 3: task7(); break;
		case 4: task8(); break;
		default: cout << "there is no task with such a number" << endl; menu();
		}
	}
	else cout << endl;

}

int main()
{
	cout << "Hello! you are in homework 6" << endl;
	menu();
	cout << "Goodbye";
}

