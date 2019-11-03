#include <iostream>
#include <string>
#include "class_h.h"
using namespace std;




bool checkwords(char* a, char* b)
{
	
	for (int i = 0; i < 1000; i++)
	{
		if (a[i] != b[i])
			return false;
	}
	
	return true;
	

}


void cl281019()
{
	string s;
	getline(cin, s);
	int n = s.length();
	char* text = new char[n];
	for (int i = 0; i < n; i++)
		text[i] = s[i];

	

	int Num_words = 0;
	bool Is_word = text[0] != ' ';
	if (Is_word)
		Num_words++;
	for (int i = 1; i < n; i++)
	{
		if (Is_word)
		{
			if (text[i] == ' ')
				Is_word = 1 - Is_word;
		}
		else
			if (text[i] != ' ')
			{
				Is_word = 1 - Is_word;
				Num_words++;
			}
	}

	cout << "Number of words: " << Num_words << endl;



	int quant_num = 0;
	int quant_let = 0;
	for (int i = 0; i < n; i++)
	{
		if ((int)text[i] < 58 && (int)text[i] > 47)
			quant_num++;
		if ((int)text[i] < 91 && (int)text[i] > 64)
			quant_let++;
		if ((int)text[i] < 123 && (int)text[i] > 96)
			quant_let++;
	}

	cout << "Number of letters: " << quant_let << endl;
	cout << "Number of numbers: " << quant_num << endl;



	char** words = new char*[Num_words];
	for (int i = 0; i < Num_words; i++)
		words[i] = new char[1000];
	int word_ind = 0;
	int st_word;
	Is_word = text[0] != ' ';

	if (Is_word)
	{
		words[0][0] = text[0];
		st_word = 0;
	}

	for (int i = 1; i < n; i++)
	{
		if (Is_word)
		{
			if (text[i] != ' ')
				words[word_ind][i - st_word] = text[i];
			else
			{
				Is_word = 1 - Is_word;
				word_ind++;
			}

		}
		else
		{
			if (text[i] != ' ')
			{
				st_word = i;
				words[word_ind][0] = text[i];
				Is_word = 1 - Is_word;
			}
		}
	}

	int h = 0;


	for (int i = 0; i < Num_words -1; i++)
		for (int j = i + 1; j < Num_words; j++)
			if (checkwords(words[i], words[j]))
				h++;

	cout << "Number of identical pairs is " << h << endl;

	
	
	

	
}
