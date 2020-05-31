#include "Matrix.h"
#pragma warning(disable: 4996)
char filename_big_matrix[] = "Larger.bin";
char filename_small_matrix[] = "Smaller.bin";
void Larger_List::push_back(int f)
{
	Node<int>* add = new Node<int>;
	add->data = f;
	if (!head)
	{
		head = add;
		head->previous = nullptr;
		head->following = tail;
	}
	else
	{
		if (!tail)
		{
			add->previous = head;
			head->following = add;
			add->following = nullptr;
			tail = add;

		}
		else
		{
			tail->following = add;
			add->previous = tail;
			tail = add;
		}
	}
}

void Larger_List::push_front(int f)
{
	Node<int>* add = new Node<int>;
	add->data = f;
	if (!head)
	{
		head = add;
		head->previous = nullptr;
		head->following = tail;
	}
	else
	{
		if (!tail)
		{
			tail = head;
			tail->previous = add;
			add->following = tail;
		}
		else
		{
			add->following = head;

		}
	}
}

void Larger_List::remove(int f)
{
	Node<int>* remove_item = nullptr;
	for (Node<int>* i = head; i; i = i->following)
	{
		if (i->data == f)
		{
			remove_item = i;
			break;
		}
	}
	if (remove_item)
	{
		if (remove_item->previous)
			remove_item->previous->following = remove_item->following;
		else
			head = remove_item->following;
		if (remove_item->following)
			remove_item->following->previous = remove_item->previous;
		else
			tail = remove_item->previous;
	}

}

void Matrix::push_back(Larger_List f)
{
	Node<Larger_List>* add = new Node<Larger_List>;
	add->data = f;
	if (!head)
	{
		head = add;
		head->previous = nullptr;
		head->following = tail;
	}
	else
	{
		if (!tail)
		{
			add->previous = head;
			head->following = add;
			add->following = nullptr;
			tail = add;

		}
		else
		{
			tail->following = add;
			add->previous = tail;
			tail = add;
		}
	}
}

void Matrix::Write_2_types_in_file()
{
	ofstream f;
	f.open(filename_big_matrix, ios::binary);
	for (Node<Larger_List>* i = head; i; i = i->following)
	{
		for (Node<int>* j = i->data.head; j; j = j->following)
			f.write((char*)& j->data, sizeof(int));
	}
	f.close();


	f.open(filename_small_matrix, ios::binary);

	struct Cell
	{
		 int data, xpos, ypos;
	} temp;

	int x, y;
	x = 0;

	for (Node<Larger_List>* i = head; i; i = i->following)
	{
		y = 0;
		for (Node<int>* j = i->data.head; j; j = j->following)
		{
			if (j->data != 0) {
				temp.data = j->data;
				temp.xpos = x;
				temp.ypos = y;
				f.write((char*)& temp, sizeof(Cell));
			}
			y++;
		}
		x++;
	}


}

void Compare()
{
	int size_of_big, size_of_small;
	FILE* f;
	f = fopen(filename_big_matrix, "rb");
	fseek(f, 0, SEEK_END);
	size_of_big = ftell(f);
	fclose(f);

	f = fopen(filename_small_matrix, "rb");
	fseek(f, 0, SEEK_END);
	size_of_small = ftell(f);
	fclose(f);

	cout << "We have saved in " << size_of_big / size_of_small << " times less memory than the original matrix" << endl;
	system("pause");
	
}

void Matrix::Set_Matrix()
{
	
	int my_num;
	cout << "Enter the number: ";
	cin >> my_num;
	int x = 1;
	for (Node<Larger_List>* i = head; i; i = i->following)
	{
		if (my_num % x == 0)
		{
			int k = 0;
			for (Node<int>* j = i->data.head; k < my_num / x && j; j = j->following)
			{
				j->data = my_num;
				k++;
			}
		}

		x++;
	}
	
}






void One_Matrix()
{
	Matrix a;
	a.Set_Matrix();
	a.Write_2_types_in_file();
	Compare();
}


void Add_2_Matrixes()
{
	Matrix a, b,c;
	cout << "First matrix" << endl;
	a.Set_Matrix();

	cout << "Second matrix" << endl;
	b.Set_Matrix();

	for (Node<Larger_List>*  ia = a.head, *ib = b.head, *ic = c.head; ia, ib, ic; ia = ia->following, ib = ib->following, ic = ic->following)
	{
		for (Node<int>* ja = ia->data.head, *jb = ib->data.head, *jc = ic->data.head; ja, jb, jc; ja = ja->following, jb = jb->following, jc = jc->following)
		{
			jc->data = ja->data + jb->data;
		}
	}

	c.Write_2_types_in_file();
	Compare();
}


void Multiply_2_Matrixes()
{
	Matrix a, b, c;
	cout << "First matrix" << endl;
	a.Set_Matrix();

	cout << "Second matrix" << endl;
	b.Set_Matrix();

	for (Node<Larger_List>* ia = a.head, *ib = b.head, *ic = c.head; ia, ib, ic; ia = ia->following, ib = ib->following, ic = ic->following)
	{
		for (Node<int>* ja = ia->data.head, *jb = ib->data.head, *jc = ic->data.head; ja, jb, jc; ja = ja->following, jb = jb->following, jc = jc->following)
		{
			jc->data = ja->data * jb->data;
		}
	}

	c.Write_2_types_in_file();
	Compare();
}