#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

char IntoInt(char q)
{
	int y = (int)q;
	y = y % 10;
	y += 48;
	q = (char)y;
	return q;
}

int convert(char* a, int n)
{
	int y = 0;
	for (int i = 0; i < n; i++)
		y += ((int)a[i] - 48) * pow(10, 3 - i);
	return y;
}

class Lapt
{
private:
	int len_name;
	char* name;
	char* weight;
	char* size;
	char* RAM;
	char* diagonal;
	char* videocard;
	char* display;
	char* regeneration;
	char* hdd;
public:
	char* price;
	char* frequency;
	bool Exist = 1;
	
	
	void Enterings(ifstream &qw)
	{
		hdd = new char[5];
		regeneration = new char[2];
		display = new char[9];
		videocard = new char[1];
		diagonal = new char[4];
		RAM = new char[2];
		frequency = new char[3];
		size = new char[14];
		weight = new char[3];
		price = new char[4];
		string s = "";
		int sum = 5 + 2 + 9 + 1 + 4 + 2 + 3 + 14 + 3 + 4;
		if (!qw.eof())
		{
			getline(qw, s);
			if (s.length() > sum + 20 + 10 && s.length() < sum + 10)
			{
				cout << "The input is incorrect" << endl;
				return;
			}

			

			//entering block
			{
			int i = s.length() - 1;
			int sti = i - 5;
			// hdd
			while (i > sti)
			{
				hdd[i - sti - 1] = s[i];
				i--;
			}
			i--;

			//regeneration
			sti = i - 2;
			while (i > sti)
			{
				regeneration[i - sti - 1] = s[i];
				i--;
			}
			i--;

			//display
			sti = i - 9;
			while (i > sti)
			{
				display[i - sti - 1] = s[i]; i--;
			}
			i--;

			//videocard
			sti = i - 1;
			while (i > sti)
			{
				videocard[i - sti - 1] = s[i]; i--;
			}
			i--;

			//diagonal
			sti = i - 4;
			while (i > sti)
			{
				diagonal[i - sti - 1] = s[i]; i--;
			}
			i--;

			//RAM
			sti = i - 2;
			while (i > sti)
			{
				RAM[i - sti - 1] = s[i]; i--;
			}
			i--;

			//frequency
			sti = i - 3;
			while (i > sti)
			{
				frequency[i - sti - 1] = s[i]; i--;
			}
			i--;

			//size
			sti = i - 14;
			while (i > sti)
			{
				size[i - sti - 1] = s[i]; i--;
			}
			i--;

			//weight
			sti = i - 3;
			while (i > sti)
			{
				weight[i - sti - 1] = s[i]; i--;
			}
			i--;

			//price
			sti = i - 4;
			while (i > sti)
			{
				price[i - sti - 1] = s[i]; i--;
			}
			i--;
			name = new char[i + 1];
			len_name = i + 1;
			while (i >= 0)
			{
				name[i] = s[i]; i--;
			}
			}
			weight[1] = '.';
			size[2] = '.';
			size[4] = 'x';
			size[7] = '.';
			size[9] = 'x';
			size[12] = '.';
			diagonal[2] = '.';
			display[4] = 'x';
			hdd[1] = '.';

		}
	}

	void Output(ofstream &qw)
	{
		// name
		for (int i = 0; i < len_name; i++)
		{
			qw << name[i];
		}
		qw << ' ';
		// price
		for (int i = 0; i < 4; i++)
		{
			qw << price[i];
		}
		qw << ' ';
		// weight
		for (int i = 0; i < 3; i++)
		{
			qw << weight[i];
		}
		qw << ' ';
		// size
		for (int i = 0; i < 14; i++)
		{
			qw << size[i];
		}
		qw << ' ';
		// frequency
		for (int i = 0; i < 3; i++)
		{
			qw << frequency[i];
		}
		qw << ' ';
		// RAM
		for (int i = 0; i < 2; i++)
		{
			qw << RAM[i];
		}
		qw << ' ';
		// diagonal
		for (int i = 0; i < 4; i++)
		{
			qw << diagonal[i];
		}
		qw << ' ';
		// videocard
		for (int i = 0; i < 1; i++)
		{
			qw << videocard[i];
		}
		qw << ' ';
		// display
		for (int i = 0; i < 9; i++)
		{
			qw << display[i];
		}
		qw << ' ';
		// regeneration
		for (int i = 0; i < 2; i++)
		{
			qw << regeneration[i];
		}
		qw << ' ';
		// hdd
		for (int i = 0; i < 5; i++)
		{
			qw << hdd[i];
		}
		qw << endl;
	}
	
};

void Laptop()
{
	ifstream qw;
	qw.open("C:\\Users\\aaade\\Desktop\\Files for labs\\note.txt");
	int num = 0;
	while (!qw.eof())
	{
		string s = "";
		getline(qw, s);
		num++;
	}
	qw.seekg(0);
	Lapt* mas = new Lapt[num];
	for (int i = 0; i < num; i++)
	{
		mas[i].Enterings(qw);
		if (convert(mas[i].price, 4) < 3500)
			mas[i].Exist = 0;
	}
	qw.close();


	// sorting part
	for (int i = 0; i < num - 1; i++)
		for (int j = i; j < num; j++)
			if (convert(mas[i].frequency, 3) > convert(mas[j].frequency, 3))
			{
				Lapt f = mas[i];
				mas[i] = mas[j];
				mas[j] = f;
			}


	ofstream qa;
	qa.open("C:\\Users\\aaade\\Desktop\\Files for labs\\note1.txt");
	for (int i = 0; i < num; i++)
	{
		if (mas[i].Exist == 1)
			mas[i].Output(qa);
	}
	qa.close();


	/*int num1 = 0;
	for (int i = 0; i < num; i++)
	{
		if (IntoInt(mas[i].price, 4)>3500)
		{
			num1++;
		}
	}
	Lapt* mas1 = new Lapt[num1];
	int zsuv = 0;
	for (int i = 0; i < num; i++)
	{
		if (IntoInt(mas[i].price, 4) > 3500)
			mas1[i - zsuv] = mas[i];
		else
			zsuv++;
	}
	delete[] mas;

	ofstream qw1;
	qw1.open("C:\\Users\\aaade\\Desktop\\Files for labs\\netet.dat");
	qw1.close();

	FILE* f;
	f = fopen("C:\\Users\\aaade\\Desktop\\Files for labs\\netet.dat", "wb");
	for (int i = 0; i < num1; i++)
	{
		fwrite(&mas1[i], sizeof(Lapt), 1, f);
		char t = '\n';
		fwrite(&t, sizeof(char), 1, f);

	}*/
}