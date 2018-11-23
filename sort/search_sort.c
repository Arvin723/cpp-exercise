#include<stdio.h>

void search_sort(int * a,int n);

int main()
{
	int a[10] = {3, 1, 8, 2, 4, 9, 0, 5, 7, 6};
	search_sort(a, 10);
	for ( int i = 0; i <10; i++)
	{
		printf("%d ",a[i]);
	}
}

void search_sort(int * a,int n)
{
	for (int j = 0; j < n-1; j++)
	{
		int _min = j;
		for (int i = j+1; i < n; i++)
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