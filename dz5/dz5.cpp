#include <iostream>
#include "dz5h.h"
using namespace std;



int main()
{
	cout << "Hello! You are in my Homework 5." << endl;
	cout << "If you are interested in case, enter c, if in for, enter f, if in while, enter w" << endl;
	char a;
	int s;
	cout << "Your block of tasks is ";
	cin >> a;
	switch (a) {
	case 'c': cout << "Your task is "; cin >> s; switch (s) {
	case 1: task1(); break;
	case 2: task2(); break;
	case 3: task3(); break;
	case 4: task4(); break;
	case 5: task5(); break;
	} break;
	case 'f': cout << "Your task is "; cin >> s; switch (s) {
	case 1: task6(); break;
	case 2: task7(); break;
	case 3: task8(); break;
	case 4: task9(); break;
	case 5: task10(); break;
	} break;
	case 'w': cout << "Your task is "; cin >> s; switch (s) {
	case 1: task11(); break;
	case 2: task12(); break;
	case 3: task13(); break;
	case 4: task14(); break;
	case 5: task15(); break;
	} break;
	}
	
}

