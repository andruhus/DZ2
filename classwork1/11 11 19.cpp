#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

int countchar(char* str)
{
	int count = 0;
	for (int i = 0; str[i] > 0 && i<strlen(str)-1; i++) 
		count++;
	return count;
}

class Student
{
public:
	char* surname;
	char name, father;
	int group;
	int success[5];

	void SetStudent(ifstream& st_account)
	{

		if (!st_account.eof())
		{
			string s = "";
			getline(st_account, s);
			int i = 0;
			while (s[i] != ' ')
			{
				i++;
			}

			surname = new char[i];
			for (int u = 0; u < i; u++)
				surname[u] = s[u];
			i++;
			name = s[i];
			i += 2;
			father = s[i];
			
			i += 2;
			group = (int)s[i] - 48;
			i += 2;
			char ter;
			int zsuv = 0;
			for (int j = i; j < s.length(); j++)
			{
				ter = s[j];
				if (ter != ' ')
					success[j - i - zsuv] = (int)ter - 48;
				else
					zsuv++;
			}
			
		}



	}
};

void School()
{
	ifstream st_account;
	st_account.open("C:\\Users\\aaade\\Desktop\\Files for labs\\file1.txt");
	int num;
	string op = "";
	getline(st_account, op);
	num = (int)op[0] - 48;
	Student* school = new Student[num];
	
	
	for (int i = 0; i < num; i++)
		school[i].SetStudent(st_account);
	

	st_account.close();
	
	double* avg_mark = new double[num];

	for (int i = 0; i < num; i++)
	{
		double sum = 0.0;
		for (int j = 0; j < 5; j++)
			sum += (double)school[i].success[j];
		sum /= 5;
		avg_mark[i] = sum;
	}
	ofstream f1("C:\\Users\\aaade\\Desktop\\Files for labs\\file2.txt");

	for (int i = 0; i < num; i++)
	{
		int zas = avg_mark[i];
		string k = "";
		int quant = countchar(school[i].surname);
		for (int b = 0; b < quant; b++)
			k += school[i].surname[b];
		k += " ";
		int y = 5;
		while (y > 0)
		{
			y--;
			int z = avg_mark[i];
			k += (char)(z+48);
			if (y == 4)
				k += ".";
			avg_mark[i] -= z;
			avg_mark[i] *= 10;
		}
		f1 << k << "\n";
		avg_mark[i] = zas;
	}
	
	f1.close();

	ofstream f2("C:\\Users\\aaade\\Desktop\\Files for labs\\file3.txt");
	bool nuj = 0;
	double lower_mark = 5.0;
	double higher_mark = 9.0;


	for (int i = 0; i < num; i++)
		if (avg_mark[i] >= lower_mark && avg_mark[i] <= higher_mark)
		{
			nuj = 1;
			string k = "";
			int quant = countchar(school[i].surname);
			for (int b = 0; b < quant; b++)
				k += school[i].surname[b];
			k += " ";
			int y = 5;
			while (y > 0)
			{
				y--;
				int z = avg_mark[i];
				k += (char)(z + 48);
				if (y == 4)
					k += ".";
				avg_mark[i] -= z;
				avg_mark[i] *= 10;
			}
			f2 << k << "\n";
		}

	if (!nuj)
		f2 << "There is no such a student";
	f2.close();

	delete[] avg_mark;
	for (int i = 0; i < num; i++)
	{
		delete[] school[i].surname;
	}
	delete[] school;
	
	
	//f1.open("C:\\Users\\aaade\\Desktop\\Files for labs\\file2.txt");

}