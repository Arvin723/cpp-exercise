#include<stdio.h>

//������ a ��a[p]��a[r]���ֽ�������
void merge_sort(int * a, int p, int r);

//������ a ��(a[p]~a[q])��(a[q+1]~a[r]) ���߽��й鲢��
	//���������������ź�����鲢������� a �����ź����
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
	
	int i = 0;//a���±�
	int j = 0;//L_ar���±�
	int k = 0;//R_ar���±�
	
	//copy
	for (i = 0; i < L_len; i++)
	{
		L_ar[i] = a[p + i];
	}
	for (i = 0; i < R_len; i++)
	{
		R_ar[i] = a[q + i + 1];
	}
	
	for (i = p; i < r + 1; i++)//�鲢
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