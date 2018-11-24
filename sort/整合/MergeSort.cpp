#include<iostream>
#include"sort.h"

using namespace std;

void merge_sort(int * a, int p, int r)
{
	if (p < r)
	{
		int q = (r + p) / 2;
		merge_sort(a, p, q);
		merge_sort(a, q + 1, r);
		merge(a, p, q, r);
	}
	else
	{
		return;
	}
}

void merge(int * a, int p, int q, int r)
{
	int L_len = q - p + 1;
	int R_len = r - q;
	int n = r - p + 1;

	//int L_ar[L_len];
	//int R_ar[R_len];
	int  *L_ar = new int(L_len);
	int  *R_ar = new int(R_len);

	int i = 0;//a的下标
	int j = 0;//L_ar的下标
	int k = 0;//R_ar的下标

			  //copy
	for (i = 0; i < L_len; i++)
	{
		L_ar[i] = a[p + i];
	}
	for (i = 0; i < R_len; i++)
	{
		R_ar[i] = a[q + i + 1];
	}

	for (i = p; i < r + 1; i++)//归并
	{
		if (j == L_len)
		{
			a[i] = R_ar[k];
			k++;
		}
		else if (k == R_len)
		{
			a[i] = L_ar[j];
			j++;
		}
		else if (L_ar[j] <= R_ar[k])
		{
			a[i] = L_ar[j];
			j++;
		}
		else
		{
			a[i] = R_ar[k];
			k++;
		}
	}
}


void merge_sort(int * a, int p, int r, int *t)
{
	if (p < r)
	{
		int q = (r + p) / 2;
		merge_sort(a, p, q, t);
		merge_sort(a, q + 1, r, t);
		merge(a, p, q, r, t);
	}
	else
	{
		return;
	}
}

void merge(int * a, int p, int q, int r, int *t)
{
	int L_len = q - p + 1;
	int R_len = r - q;
	int n = r - p + 1;

	//int L_ar[L_len];
	//int R_ar[R_len];
	int  *L_ar = new int(L_len);
	int  *R_ar = new int(R_len);

	int i = 0;//a的下标
	int j = 0;//L_ar的下标
	int k = 0;//R_ar的下标

			  //copy
	for (i = 0; i < L_len; i++)
	{
		L_ar[i] = a[p + i];
	}
	for (i = 0; i < R_len; i++)
	{
		R_ar[i] = a[q + i + 1];
	}

	for (i = p; i < r + 1; i++)//归并
	{
		if (j == L_len)
		{
			a[i] = R_ar[k];
			k++;
		}
		else if (k == R_len)
		{
			a[i] = L_ar[j];
			j++;
		}
		else if (L_ar[j] <= R_ar[k])
		{
			a[i] = L_ar[j];
			j++;
		}
		else
		{
			a[i] = R_ar[k];
			k++;
			(*t) += (L_len - j);
		}
	}
	return;
}