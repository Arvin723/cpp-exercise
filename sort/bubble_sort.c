#include<stdio.h>

void bubble_sort(int* a, int n);

int main()
{
	int a[10] = {4, 6, 1, 2, 8, 9, 0, 5, 3, 7};
	bubble_sort(a, 10);
	for (int i = 0; i < 10; i++)
	printf("%d ",a[i]);
}

void bubble_sort(int* a, int n)
{
	int tem = 0;
	for (int j = n; j > 0; j--)
	{
		for (int i = 1; i < n; i++)
		{
			if (a[i] < a[i-1])
			{
				tem = a[i];
				a[i] = a[i-1];
				a[i-1] = tem;
			}
		}
	}
}