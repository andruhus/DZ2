#include "fily.h"
#include <iostream>
#include <math.h>
using namespace std;

/*ƒаны координаты двух различных полей шахматной доски x1, y1,
x2, y2 (целые числа, лежащие в диапазоне 1Ц8). ѕроверить истинность вы-
сказывани€: Ђ онь за один ход может перейти с одного пол€ на другоеї.*/

void task7()
{
	cout << "The coordinates of two different checkerboard fields x1, y1,x2, y2(integers in the range 1Ц8).Check the truth you tales : УA horse can move from one field to another in one moveФ" << endl;
	cout << "Enter two chess positions ";
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	bool q = ((abs(x2 - x1) == 1 & abs(y2 - y1) == 2) || (abs(x2 - x1) == 2 & abs(y2 - y1) == 1));
	cout << q << endl;
}