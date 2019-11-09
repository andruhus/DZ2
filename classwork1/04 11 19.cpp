#include <iostream>
#include <string>
using namespace std;


// task 1
bool charcompare(char a, char b)
{
	if (96 < (int)a && (int)a < 123)
		a -= 32;
	if (96 < (int)b && (int)b < 123)
		b -= 32;
	return a < b;
}

bool wordcompare(char* a, char* b)
{
	for (int i = 0; i < 1000; i++)
	{
		if (a[i] == b[i] || a[i] - 32 == b[i] || a[i] == b[i] -32)
			continue; 
		else if (!charcompare(a[i], b[i]))
			return false;
		else
			return true;
	}
	return false;
}

void quickSortalfa(char** arr, int left, int right) {

	int i = left, j = right;

	char* tmp;

	char* pivot = arr[(left+right)/2];



	/* partition */

	while (i <= j)
	{

		while (wordcompare(arr[i],pivot))

			i++;

		while (wordcompare(pivot,arr[j]))

			j--;

		if (i <= j)
		{

			tmp = arr[i];

			arr[i] = arr[j];

			arr[j] = tmp;

			i++;

			j--;

		}

	};



	/* recursion */

	if (left < j)

		quickSortalfa(arr, left, j);

	if (i < right)

		quickSortalfa(arr, i, right);

}

void alfa_sort()
{
	// input part
	cout << "Enter your text" << endl;
	cout << "When you complete typing the text press double ENTER" << endl;
	cout << "	";
	string u = "";
	string t;
	do
	{
		getline(cin, t);
		u += t;
	} while (t != "");

	// text the array of all the characters
	int n = u.length();
	char* text = new char[n];
	for (int i = 0; i < n; i++)
		text[i] = u[i];




	// now we create words - the array of word (splited by spaces) 
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

	char** words = new char* [Num_words];
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


	// sorting part
	quickSortalfa(words, 0, Num_words - 1);

	cout << endl;


	// output part
	for (int i = 0; i < Num_words; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			if (words[i][j] == words[i][999])
				break;
			cout << words[i][j];
		}
		cout << " ";
	}




	
}



// task 2

int wordlen(char* a)
{
	int i = 0;
	while (a[i] != a[999])
	{
		i++;
	}
	return i;
}

void quickSortbeta1(char** arr, int left, int right) {

	int i = left, j = right;

	char* tmp;

	char* pivot = arr[(left + right) / 2];



	/* partition */

	while (i <= j)
	{

		while (wordlen(arr[i]) < wordlen(pivot))

			i++;

		while (wordlen(pivot) < wordlen(arr[j]))

			j--;

		if (i <= j)
		{

			tmp = arr[i];

			arr[i] = arr[j];

			arr[j] = tmp;

			i++;

			j--;

		}

	};



	/* recursion */

	if (left < j)

		quickSortbeta1(arr, left, j);

	if (i < right)

		quickSortbeta1(arr, i, right);

}

void quickSortbeta2(char** arr, int left, int right) {

	int i = left, j = right;

	char* tmp;

	char* pivot = arr[(left + right) / 2];



	/* partition */

	while (i <= j)
	{

		while (wordlen(arr[i]) > wordlen(pivot))

			i++;

		while (wordlen(pivot) > wordlen(arr[j]))

			j--;

		if (i <= j)
		{

			tmp = arr[i];

			arr[i] = arr[j];

			arr[j] = tmp;

			i++;

			j--;

		}

	};



	/* recursion */

	if (left < j)

		quickSortbeta2(arr, left, j);

	if (i < right)

		quickSortbeta2(arr, i, right);

}

void beta_sort()
{
	// input part
	cout << "Enter your text" << endl;
	cout << "When you complete typing the text press double ENTER" << endl;
	cout << "	";
	string u = "";
	string t;
	do
	{
		getline(cin, t);
		u += t;
	} while (t != "");

	// text the array of all the characters
	int n = u.length();
	char* text = new char[n];
	for (int i = 0; i < n; i++)
		text[i] = u[i];




	// now we create words - the array of word (splited by spaces) 
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

	char** words = new char* [Num_words];
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


	// sorting part
	int j;
	cout << "if you want to sort words ascending enter an even number" << endl;
	cout << "if you want to sort words descending enter an odd number" << endl;
	cin >> j;
	if (j % 2 == 0)
		quickSortbeta1(words, 0, Num_words - 1);
	else
		quickSortbeta2(words, 0, Num_words - 1);


	// output part
	for (int i = 0; i < Num_words; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			if (words[i][j] == words[i][999])
				break;
			cout << words[i][j];
		}
		cout << " ";
	}
}