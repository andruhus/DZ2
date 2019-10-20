

#include <iostream>
#include "dz8h.h"
using namespace std;


void menu()
{
	int a;
	int k;
	cout << "Enter your part of tasks: ";
	cin >> a;
	if (a == 1) {
		cout << "Enter your task: ";
		cin >> k;
		switch (k) {
		case 1: task1(); break;
		case 2: task2(); break;
		default: cout << "there is no task with such a number" << endl; menu();
		}
	}
	else if (a == 2)
	{
		cout << "Enter your task: ";
		cin >> k;
		switch (k) {
		case 1: task3(); break;
		case 2: task4(); break;
		case 3: task5(); break;
		default: cout << "there is no task with such a number" << endl; menu();
		}
	}
	else if (a == 3)
	{
		cout << "Enter your task: ";
		cin >> k;
		switch (k) {
		case 1: task6(); break;
		case 2: task7(); break;
		case 3: task8(); break;
		default: cout << "there is no task with such a number" << endl; menu();
		}
	}
	else if (a == 4)
	{
		cout << "Enter your task: ";
		cin >> k;
		switch (k) {
		case 1: task9(); break;
		case 2: task10(); break;
		case 3: task11(); break;
		case 4: task12(); break;
		default: cout << "there is no task with such a number" << endl; menu();
		}
	}
	else if (a == 0) return;
	else cout << "there is no such a block of tasks. If you want to exit press 0 " << endl; menu();

}


int main()
{
	cout << "Hello! You are in my homework 8!" << endl;
	menu();
	cout << "Goodbye" << endl;
}

