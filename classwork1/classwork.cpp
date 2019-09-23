
#include <iostream>
#include <math.h>
using namespace std;

void pr(float f, bool isNot0)
{
	if (isNot0) cout << f << endl;
	else cout << (int)f << endl;
}

void oper(float x, float a,float b, float c, bool isNot0)
{
	float f = 0;
	if (x + 5 < 0 && c == 0) {
		f = 1 / a * x - b;	
	}

	else if (x + 5 > 0 && c != 0) {
		f = (x - a) / x;
	}
	else {
		f = 10 * x / (c - 4);
	}
	pr(f, isNot0);
}

int main()
{
	float a, b, c;
	float xStart, xEnd, dx;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> xStart;
	cin >> xEnd;
	cin >> dx;
	int aw = int(a);
	int bw = int(b);
	int cw = int(c);
	bool isNot0 = true;
	if ((aw == 0 && bw == 0) || (bw == 0 && cw == 0)) {
		isNot0 = false;
	}
	for (float x = xStart; x < xEnd + dx; x = x + dx)
	{
		cout << int((x - xStart)/dx)+1 << ") " << x << " --> ";
		oper(x, a, b, c, isNot0);
		
	}
	return 0;
}

