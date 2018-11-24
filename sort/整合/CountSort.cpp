#include<iostream>
#include"sort.h"

void CountSort(int * a, int n)
{
	int k = MaxNum(a, n);
	int * b = new int[n];
	//数组a中最小为0，最大数为k，故c的大小为k+1
	int * c = new int[k+1];

	for (int i = 0; i < k+1; i++)
	{
		c[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		b[i] = 0;
	}

	//数字a[i]共有c[a[i]]个
	for (int i = 0; i < n; i++)
	{
		c[a[i]]++;
	}

	//小于等于 c[i] 的有 i 个
	for (int i = 1; i < k+1; i++)
	{
		c[i] += c[i - 1];
	}

	//排序到数组 b
	for (int i = 0; i < n; i++)
	{
		b[c[a[i]]-1] = a[i];
		c[a[i]]--;
	}

	//复制到数组a
	for (int i = 0; i < n; i++)
	{
		a[i] = b[i];
	}

	delete[] c;
	delete[] b;
}

int MaxNum(int  * a, int n)
{
	int ret = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > ret)
		{
			ret = a[i];
		}
	}
	return ret;
}