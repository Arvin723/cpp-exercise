#include<iostream>
#include"sort.h"

using namespace std;

void bubble_sort(int* a, int n)
{
	int tem = 0;
	for (int j = n; j > 1; j--)
	{
		for (int i = 1; i < j; i++)
		{
			if (a[i] < a[i - 1])
			{
				tem = a[i];
				a[i] = a[i - 1];
				a[i - 1] = tem;
			}
		}
	}
}