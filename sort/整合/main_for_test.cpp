#include<iostream>
#include"sort.h"
#include"RandomizeInPlace.h"
#include<time.h>

#define N 100

using namespace std;

void print(int * a, int n)
{
	for (int i = 0; i < n; i++) 
	{
		cout <<fixed<< a[i] << " ";
	}
	cout << endl;
}

int main()
{
	int a[N];
	for (int i = 0; i < N; i++)
	{
		a[i] = i;
	}
	//�����������
	RandomizeInPlace(a, N);
	cout << "����ǰ ��" << endl;
	print(a, N);

	clock_t start, end;
	start = clock();

	//HeapSort(a, N);
	QuickSort(a, 0, N-1);
	//bubble_sort(a, N);
	//CountSort(a, N);
	//RadixSort(a, N, 3);

	end = clock();
	cout << "����� ��" << endl;

	print(a, N);

	time_t timeOfSort = end - start;
	cout << "����ʱ�䣺"<<(double)timeOfSort << endl;
}