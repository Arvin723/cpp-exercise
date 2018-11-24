#include<iostream>
#include"sort.h"

void QuickSort(int * a, int p, int r)
{
	if (p < r)
	{
		int q = Partition(a, p, r);
		QuickSort(a, p, q - 1);
		QuickSort(a, q + 1, r);
	}
}

int Partition(int * a, int p, int r)
{
	int x = a[r];
	int i = p;
	for (int j = p; j < r; j++)
	{
		if (a[j] <= x)
		{
			int tem = a[i];
			a[i] = a[j];
			a[j] = tem;
			i++;
		}
	}
	int temp = a[i];
	a[i] = a[r];
	a[r] = temp;

	return i;
}

/*
int Partition(int * a, int p, int r)
{
	int x = a[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (a[j] <= x)
		{
			i++;
			int tem = a[i];
			a[i] = a[j];
			a[j] = tem;
		}
	}
	int temp = a[i+1];
	a[i+1] = a[r];
	a[r] = temp;

	return i + 1;
}
*/

