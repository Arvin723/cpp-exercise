#include<iostream>
#include<cstdlib>
#include<ctime>
#include"RandomizeInPlace.h"

void RandomizeInPlace(int * a, int n)
{
	int tmp;
	int m;
	time_t t;
	time(&t);
	for (int i = 0; i < n; i++)
	{
		srand(i + t);
		m = rand() % (n - i) + i;
		tmp = a[i];
		a[i] = a[m];
		a[m] = tmp;
	}
}