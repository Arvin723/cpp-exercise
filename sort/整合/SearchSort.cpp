#include<iostream>
#include"sort.h"

using namespace std;

void search_sort(int * a, int n)
{
	for (int j = 0; j < n - 1; j++)
	{
		int _min = j;
		for (int i = j + 1; i < n; i++)
		{
			if (a[i] < a[_min])
			{
				_min = i;
			}
		}
		int tem = a[_min];
		a[_min] = a[j];
		a[j] = tem;
	}
}