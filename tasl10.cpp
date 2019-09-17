

#include <iostream>
#include "fily.h"
using namespace std;

void task10()
{
	cout << "The coordinates of a point that does not lie on the coordinate axes OXand OY are given. Determine the number of the coordinate quarter in which this point." << endl;
	cout << "Enter two integers ";
	int a, b;
	cin >> a >> b;
	if (a > 0) {
		if (b > 0) cout << 1 << endl;
		else cout << 4 << endl;
	}
	else if (b > 0) cout << 2 << endl;
	else cout << 3 << endl;
}