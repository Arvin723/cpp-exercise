#include<iostream>
#include"sort.h"

using namespace std;

void insert_sort(int ar[], int n)
{
	int key = 0;
	for (int i = 1; i< n; i++)
	{
		key = ar[i];
		int j = i;
		while (j > 0)
		{
			if (key < ar[j - 1])
			{
				ar[j] = ar[j - 1];
			}
			else
			{
				break;
			}
			j--;
		}
		ar[j] = key;
	}
}