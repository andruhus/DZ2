
#include <iostream>
#include "fily.h"
using namespace std;

void task11()
{
	cout << "Given a year number(positive integer).Determine a number of days this year, given that a typical year has 365 days, and leap - 366 days.A leap year is a year divisible by 4 over Inclusion of those years that are divisible by 100 and not divisible by 400 (for example measures, the years 300, 1300 and 1900 are not leap years, and 1200 and 2000 are are)." << endl;
	cout << "Enter an integer ";
	int a;
	cin >> a;
	if ((a % 4) == 0) if ((a % 100) == 0) if ((a % 400) == 0) cout << 366 << endl;
										else cout << 365 << endl;
					else cout << 366 << endl;
	else cout << 365 << endl;
}