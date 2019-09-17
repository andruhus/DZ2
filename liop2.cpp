#include "fily.h"
#include <iostream>
using namespace std;

/*Дано трехзначное число. Найти сумму и произведение его цифр.*/

void task1()
{
	int a;
	cout << "A three-digit number is given. Find the sum and product of its numbers" << endl;
	cout << "Enter your three-digit number ";
	cin >> a;
	int pid = 0;
	int dip = 1;
	while (a / 10 > 0)
	{
		pid += (a % 10);
		dip *= a % 10;
		a = a / 10;
	}
	cout << pid << " " << dip << endl;
}