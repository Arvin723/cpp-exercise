#include<stdio.h>

//将数组 a 从a[p]到a[r]部分进行排序
void merge_sort(int * a, int p, int r);

//将数组 a 左(a[p]~a[q])右(a[q+1]~a[r]) 两边进行归并，
	//若左右两部分已排好序，则归并后的数组 a 将是排号序的
void merge(int * a, int p, int q,int r);

int main()
{
	int a[40] = {3, 11, 8, 52, 4, 29, 0, 55, 7, 6, 12, 13, 31, 40, 25, 23, 26, 28, 3, 7,
								33, 31, 38, 32, 34, 39, 30, 35, 37, 36, 42, 43, 41, 40, 45, 43, 46, 48, 33, 37
							};
	int n = 40;
	merge_sort(a, 0, n-1);
	for ( int i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
	}
}

void merge_sort(int * a, int p, int r)
{
	if (p < r)
	{
		int q = (r + p)/2;
		merge_sort(a, p, q);
		merge_sort(a, q + 1, r);
		merge(a, p, q, r);
	}
	else 
	{
		return ;
	}
}

void merge(int * a, int p, int q, int r)
{
	int L_len = q - p + 1;
	int R_len = r - q;
	int n = r - p + 1;
	
	int L_ar[L_len];
	int R_ar[R_len];
	
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