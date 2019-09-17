#include <iostream>
#include "fily.h"
using namespace std;

void task9()
{
	cout << "Three numbers are given.Find the sum of the two largest of them." << endl;
	cout << "Enter three integers ";
	int a, b, c;
	cin >> a >> b >> c;
	if (a > b) {
		int y = a;
		a = b;
		b = y;
	};
		if (a > c) {
			int y = a;
			a = c;
			c = y;
		};
	cout << (b + c) << endl;

}