#include <iostream>
#include <math.h>
#include "dz5h.h"
using namespace std;

int task1help(char a)
{
	int c = 5;
	switch (a)
	{
	case 'n': c = 0; break;
	case 'e': c = 3; break;
	case 's': c = 2; break;
	case 'w': c = 1; break;
	default: cout << "Wrong symbol" << endl; break;
	}
	return c;
}


void task1()
{
	cout << "The robot can move in four directions(“n” is north, “w” is west, “s” is south, “e” is east) and take three digital codes Mands : 0 - continue moving, 1 - turn left, –1 - turn right.The symbol C is given - the initial direction of the robot and the integer N - the team sent to him.Print robot direction after execution received team." << endl;
	cout << "Your direction is ";
	int b;
	char a;
	cin >> a;
	cout << "Your command is ";
	cin >> b;
	int c = task1help(a);
	if (c == 5) task1();
	c += b;
	c = c % 4;
	switch (c)
	{
	case 0: cout << "North"; break;
	case 3: cout << "East"; break;
	case 2: cout << "South"; break;
	case 1: cout << "West"; break;
	}

}

void task2()
{
	cout << "Given an integer in the range of 10–40, which determines the number of studies tasks on a certain topic.Print a description string for the specified the number of tasks, ensuring the correct coordination of the number with the words assignment, for example: 18 - eighteen assignments, 23 - twenty three training assignments, 31 - thirty one studies." << endl;
	cout << "Your number of assignments is ";
	int a;
	cin >> a;
	string c = "";
	if (a < 20)
		switch (a) {
		case 10: c = "ten"; break;
		case 11: c = "eleven"; break;
		case 12: c = "twelve"; break;
		case 13: c = "thirdteen"; break;
		case 14: c = "fourteen"; break;
		case 15: c = "fifteen"; break;
		case 16: c = "sixteen"; break;
		case 17: c = "seventeen"; break;
		case 18: c = "eighteen"; break;
		case 19: c = "nineteen"; break;
		}

	else {
		int k = a / 10;
		switch (k) {
		case 2: c += "twenty "; break;
		case 3: c += "thirty "; break;
		case 4: c += "forty "; break;
		}
		k = a % 10;
		switch (k) {
		case 1: c += "one"; break;
		case 2: c += "two"; break;
		case 3: c += "three"; break;
		case 4: c += "four"; break;
		case 5: c += "five"; break;
		case 6: c += "six"; break;
		case 7: c += "seven"; break;
		case 8: c += "eight"; break;
		case 9: c += "nine"; break;
		}
	}
	cout << c + " assignments";

}

void task3()
{
	cout << "An integer is given in the range 100–999. Show exact description given number, for example: 256 - two hundred fifty six, 814 - in - seven hundred and fourteen. " << endl;
	cout << "Enter an integer ";
	int a;
	cin >> a;
	string c = "";
	int r = a / 100;
	switch (r) {
	case 1: c += "one hundred"; break;
	case 2: c += "two hundreds"; break;
	case 3: c += "three hundreds"; break;
	case 4: c += "four hundreds"; break;
	case 5: c += "five hundreds"; break;
	case 6: c += "six hundreds"; break;
	case 7: c += "seven hundreds"; break;
	case 8: c += "eight hundreds"; break;
	case 9: c += "nine hundreds"; break;
	}
	r = a % 100;
	if (r < 20) {
		switch (r) {
		case 1: c += " one"; break;
		case 2: c += " two"; break;
		case 3: c += " three"; break;
		case 4: c += " four"; break;
		case 5: c += " five"; break;
		case 6: c += " six"; break;
		case 7: c += " seven"; break;
		case 8: c += " eight"; break;
		case 9: c += " nine"; break;
		case 10: c += " ten"; break;
		case 11: c += " eleven"; break;
		case 12: c += " twelve"; break;
		case 13: c += " thirteen"; break;
		case 14: c += " fourteen"; break;
		case 15: c += " fifteen"; break;
		case 16: c += " sixteen"; break;
		case 17: c += " seventeen"; break;
		case 18: c += " eighteen"; break;
		case 19: c += " nineteen"; break;
		}
	}
	else {
		r = (a / 10) % 10;
		switch (r) {
		case 2: c += " twenty"; break;
		case 3: c += " thirty"; break;
		case 4: c += " fourty"; break;
		case 5: c += " fifty"; break;
		case 6: c += " sixty"; break;
		case 7: c += " seventy"; break;
		case 8: c += " eighty"; break;
		case 9: c += " ninety"; break;
		}
		r = a % 10;
		switch (r) {
		case 1: c += " one"; break;
		case 2: c += " two"; break;
		case 3: c += " three"; break;
		case 4: c += " four"; break;
		case 5: c += " five"; break;
		case 6: c += " six"; break;
		case 7: c += " seven"; break;
		case 8: c += " eight"; break;
		case 9: c += " nine"; break;
		}
	}
	cout << c;
}

void task4() {
	cout << "The eastern calendar adopted a 60-year cycle, consisting of 12 years them subcycles indicated by color names : green, red, yellow, white and black.In each subcycle, the years bear the names of animals : rats, cows, tigers, hares, dragons, snakes, horses, sheeps, monkeys, cuckoo Ritsa, dogsand pigs.Identify the name of the year if 1984 year - the beginning of the cycle : year of the green rat." << endl;
	cout << "Enter your year ";
	int a;
	cin >> a;
	string c = "year of ";
	int d = a - 1984;
	int r = (d % 60) / 12;
	switch (r) {
	case 0: c += "green "; break;
	case 1: c += "red "; break;
	case 2: c += "yellow "; break;
	case 3: c += "white "; break;
	case 4: c += "black "; break;
	}
	int k = (d % 12);
	switch (k) {
	case 0: c += "rat"; break;
	case 1: c += "cow"; break;
	case 2: c += "tiger"; break;
	case 3: c += "hare"; break;
	case 4: c += "dragon"; break;
	case 5: c += "snake"; break;
	case 6: c += "horse"; break;
	case 7: c += "sheep"; break;
	case 8: c += "monkey"; break;
	case 9: c += "hen"; break;
	case 10: c += "dog"; break;
	case 11: c += "pig"; break;
	}
	cout << c;

}

void task5()
{
	cout << "The units of mass are numbered as follows : 1 - kilogram, 2 tonnes, 3 quintals.The unit number is given masses(an integer in the range 1 - 5) and body mass in these units( number).Find the body weight in kilograms." << endl;
	cout << "Enter a number of unit ";
	int a, m;
	cin >> a;
	cout << "Enter a mass ";
	cin >> m;
	switch (a) {
	case 1: m *= 1; break;
	case 2: m *= 1000; break;
	case 3: m *= 100; break;
	}
	cout << m;
}

void task6()
{
	cout << "Given a real number - the price of 1 kg of sweets. Output cost 1,2, ..., 10 kg of sweets." << endl;
	cout << "Enter a price ";
	double a;
	cin >> a;
	for (int i = 0; i < 11; i++) cout << i * a << endl;
}

void task7()
{
	int a, b;
	cout << "Two integers A and B (A <B) are given. Find the sum of all integers from A to B inclusive." << endl;
	cout << "Enter your A and B ";
	cin >> a >> b;
	int s = 0;
	for (int i = a; i < b + 1; i++) s += i;
	cout << s;
}

void task8()
{
	cout << "An integer N (> 0) is given. Find the sum: N^2 + (N + 1)^2 + (N + 2)^2 + ... + (2 · N)^2" << endl;
	cout << "Enter your N ";
	int n;
	cin >> n;
	int s = 0;
	for (int i = n; i < 2 * n + 1; i++) s += i * i;
	cout << s;
}

void task9()
{
	cout << "An integer N(> 1) is given.The sequence of Fibonacci numbers FK (integer type) is defined as follows : F1 = 1, F2 = 1, FK = FK – 2 + FK – 1, K = 3, 4, .... Output elements F1, F2, ..., FN" << endl;
	cout << "Enter N ";
	int n;
	cin >> n;
	int a, b;
	a = 1;
	cout << a << endl;
	b = 1;
	cout << b << endl;
	for (int i = 3; i < n + 1; i++) { cout << a + b << endl; int q = a; a = b; b = q + b; }
}

void task10()
{
	cout << "An integer N (> 0) is given. Find the sum of 1^1 + 2^2 + ... + N^N" << endl;
	cout << "Enter your N ";
	int n;
	cin >> n;
	float s = 0;
	float r = 1;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 0; j < i; j++) r *= i;
		s += r;
		r = 1;
	}
	cout << s;
}

void task11()
{
	cout << "Given an integer N (> 0), which is some degree of number 2: N = 2^K.Find an integer K is an exponent of this degree." << endl;
	cout << "Enter your number ";
	int a;
	cin >> a;
	int k = 0;
	while (a > 1) { a /= 2; k++; }
	cout << k;
}

void task12()
{
	cout << "An integer N(> 1) is given.Find the smallest integer K for which is right an inequality 3^K> N" << endl;
	cout << "Enter your N ";
	int n;
	cin >> n;
	int k = 0;
	int d = 1;
	int q = 0;
	while (d <= n)
	{
		q = k;
		while (q > 0)
		{
			d *= 3;
			q--;
		}
		k++;
	}
	cout << k++;
}


void task13()
{
	cout << "An integer N(> 1) is given.Derive the largest integer K for which sum 1 + 2 + ... + K will be less than or equal to N, and this sum itself." << endl;
	cout << "enter N ";
	int n;
	cin >> n;
	int k = 1;
	int s = 0;
	while (s <= n)
	{
		s += k;
		k++;
	}
	k -= 2;
	cout << k;

}

void task14()
{
	cout << "An integer N (> 0) is given. Using division operations whole and take these sums from the division, find the number and the sum of its numbers." << endl;
	cout << "Enter an integer ";
	int n;
	cin >> n;
	int s = 0;
	int q = 0;
	while (n > 0)
	{
		q++;
		s += n % 10;
		n = n / 10;
	}
	cout << q << " " << s;
}

void task15()
{
	cout << "An integer N(> 1) is given.Find the first Fibonacci number greater than N." << endl;
	cout << "Enter your N ";
	int n;
	cin >> n;
	int a = 1;
	int b = 1;
	while (b <= n)
	{
		int q = a;
		a = b;
		b = q + b;
	}
	cout << b;
}
