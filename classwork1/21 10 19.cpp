#include <iostream>
#include <math.h>
#include "class_h.h"
using namespace std;

// point - the struct for coordinates of the point
struct point
{
	float x, y;
};


// vector - the struct for coordinates of the vector
struct vector
{
	float x, y;
};


// pointres contains the information about the points of triangle and the difference we have found
struct pointres
{
	float res;
	point a, b, c;
};


// this function forms the vector from the coordinates of 2 points
vector differ(point a,point b)
{
	vector ab;
	ab.x = b.x - a.x;
	ab.y = b.y - a.y;
	
	return ab;
}


// the function finds the radius of the outer circle by its points A,B,C and the BC side
float radius(point a, point b, point c, float bc)
{
	float k = differ(a, b).x * differ(a, c).x + differ(a,b).y * differ(a,c).y;
	k /= sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
	k /= sqrt((c.x - a.x) * (c.x - a.x) + (c.y - a.y) * (c.y - a.y));
	k = sqrt(1 - k * k);
	float rad = bc / 2;
	rad /= k;
	return rad;
}


// this function finds the height of the triangle from the point A  or the first given point of triangle
float height(point a, point b, point c)
{
	float h = 0;
	h += a.x;
	float q = (c.x - b.x)/(b.y - c.y);
	float z = (b.x - c.x) * c.y / (b.y - c.y) - c.x;
	h += q * a.y;
	h += z;
	h /= sqrt((b.x - c.x) * (b.x - c.x) + (b.y - c.y) * (b.y - c.y));
	return h;
}


// this function finds the difference we are looking for
float resul(point a,point b,point c)
{
	
	float bc = sqrt((b.x - c.x) * (b.x - c.x) + (b.y - c.y) * (b.y - c.y));
	float pi = 4 * atan(1);
	float S_circle = pi * radius(a, b, c, bc) * radius(a, b, c, bc);
	float S_triangle = 0.5 * height(a, b, c) * bc;
	return S_circle - S_triangle;

	
}


// this function checks if the three points are on the one line
bool Is_on_line(point a, point b, point c)
{
	if (a.x == 0)
		a.x = 0.001*a.y;
	if (b.x == 0)
		b.x = 0.001*b.y;
	if (c.x == 0)
		c.x = 0.001*c.y;
	if (a.y == 0)
		a.y = 0.001*a.x;
	if (b.y == 0)
		b.y = 0.001*b.x;
	if (c.y == 0)
		c.y = 0.001*c.x;
	bool k = differ(a, b).x / differ(a, b).y - differ(a, c).x / differ(a, c).y < 0.01;
	return k;
}

void cl2110()
{
	// the input
	int n;
	cout << "Enter how many points we will have" << endl;
	cin >> n;
	while (n <= 0)
	{
		cout << "Bad n" << endl;
		cin >> n;
	}
	
	// it is the array which contains the information about every point we enter
	point* mas1 = new point[n];
	for (int i = 0; i < n; i++)
		cin >> mas1[i].x >> mas1[i].y;

	int j = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (mas1[i].x == -987 && mas1[i].y == -987)
		{
			continue;
		}
		for (int z = i + 1; z < n; z++)
			if (mas1[i].x == mas1[z].x && mas1[i].y == mas1[z].y)
			{
				j++;
				mas1[z].x = -987;
				mas1[z].y = -987;
			}
	}
	// but it can contain some repetitions
	// so mas will have all our points without repetitions in a new array
	point* mas = new point[(n-j)];
	

	int y = 0;
	for (int i = 0;i<n;i++)
	{
		if (mas1[i].x != -987 && mas1[i].y != -987)
			mas[i-y] = mas1[i];
		else
			y++;
	}

	n -= j;
	
	point a, b, c;
	// it will check if we have any triangle
	bool Existance = 0;



	// it is the array which contains the information about every triangle(its points) and the differense between the squares
	int dov = ((n * (n - 1) * (n - 2)) / 6);
	pointres* masres = new pointres[dov];


	// q is the index of maxres
	int q = 0;

	// m is a number of such triangles that does not exists
	int m = 0;

	// now we are going to full  the maxres by every combination of three points
	for (int i = 0; i < n - 2; i++)
	{
		a = mas[i];
		for (int j = i + 1; j < n - 1; j++)
		{
			b = mas[j];
			for (int u = j + 1; u < n; u++)
			{
				c = mas[u];
				if (Is_on_line(a, b, c))
				{
					m++;
					continue;
				}
				else
					Existance = 1;
				masres[q].res = resul(a, b, c);
				masres[q].a = a;
				masres[q].b = b;
				masres[q].c = c;
				q++;
			}
		}
	}


	// now we will find the minimal result
	pointres minres = masres[0];
	// the last m results are filled with garbage so we shold not count them
	for(int i = 0; i < (n * (n - 1) * (n - 2) / 6) - m; i++)
		if (masres[i].res < minres.res)
			minres = masres[i];

	
	
	// lets output our result
	if (Existance)
	{
		cout << "A: " << minres.a.x << " " << minres.a.y << endl;
		cout << "B: " << minres.b.x << " " << minres.b.y << endl;
		cout << "C: " << minres.c.x << " " << minres.c.y << endl;
	}
	else
		cout << "There is no triangle" << endl;

	delete[] mas1;
	delete[] mas;
	delete[] masres;
	

}