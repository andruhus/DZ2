#include <iostream>
#include <string>
#include "dz9h.h"
using namespace std;




void task1()
{
	cout << "Given a non-empty string S. Print a string containing the characters S, between which one space is inserted." << endl;
	string s;
	
	getline(cin, s);
	getline(cin, s);
	
	for (char er : s)
	{
		
		cout << er << ' ';
	}
}


void task2()
{
	cout << "Given a string containing at least one space character. You- lead a substring between the first and last space source line.If the line contains only one space, then output empty string." << endl;
	string s,z;
	getline(cin, z);
	getline(cin, s);
	string h = "";
	int o = 0;
	int i = 0;
	while (o < 2 && i < s.length() - 1)
	{
		if (s[i] == ' ')
			o++;
		if (o)
			h += s[i];
		i++;

	}
	for (char t : h)
		cout << t;
	cout << endl;
}

void task3()
{
	cout << "Given a string containing the full name of the file, that is, the name of the disk, directory juice(path), nameand extension proper.Highlight from this strings file name(without extension)." << endl;
	string s;
	getline(cin, s);
	getline(cin, s);
	string h;
	for (int i = 0;i<s.length();i++)
	{
		if (s[i] == '\\' )
			h = s.substr(i+1, s.length());
	}
	
	for (int i = 0; i < s.length(); i++)
	{
		if (h[i] != '.')
			cout << h[i];
		else
		{
			cout << endl;
			break;
		}
	}
}

bool in(char e)
{
	bool q = false;
	int y = (int)e;
	q = y < 91 && y > 64;
	q = q || (y > 96 && y < 123);
	return q;
}

void task4()
{
	cout << "Given a string containing numbers and lowercase Latin letters. If the letters in the string are sorted alphabetically, then print 0; otherwise output the number of the first character of the line that violates the alphabetic a row." << endl;
	string s;
	getline(cin, s);
	getline(cin, s);
	int min = 90;
	for (char e : s)
		if (in(e))
		{ 
			if ((int)e < min)
			{
				cout << "it is not sorted" << endl;
				return;
			}
			else min = (int)e;
		}
	cout << "It is sorted" << endl;
}

