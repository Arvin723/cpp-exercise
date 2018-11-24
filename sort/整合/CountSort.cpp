#include<iostream>
#include"sort.h"

void CountSort(int * a, int n)
{
	int k = MaxNum(a, n);
	int * b = new int[n];
	//����a����СΪ0�������Ϊk����c�Ĵ�СΪk+1
	int * c = new int[k+1];

	for (int i = 0; i < k+1; i++)
	{
		c[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		b[i] = 0;
	}

	//����a[i]����c[a[i]]��
	for (int i = 0; i < n; i++)
	{
		c[a[i]]++;
	}

	//С�ڵ��� c[i] ���� i ��
	for (int i = 1; i < k+1; i++)
	{
		c[i] += c[i - 1];
	}

	//�������� b
	for (int i = 0; i < n; i++)
	{
		b[c[a[i]]-1] = a[i];
		c[a[i]]--;
	}

	//���Ƶ�����a
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