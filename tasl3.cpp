#include "fily.h"
#include <iostream>
using namespace std;

/*Дан номер некоторого года (целое положительное число). Опреде-
лить соответствующий ему номер столетия, учитывая, что, к примеру, на-
чалом 20 столетия был 1901 год.*/

void task3()
{
	cout << "Given the number of some year (a positive integer). Define-pour the corresponding century number, given that, for example, the beginning of the 20th century was 1901" << endl;
	cout << "Enter your year ";
	int a;
	cin >> a;
	a = a - 1;
	a = a / 100;
	a++;
	cout << a << endl;
}