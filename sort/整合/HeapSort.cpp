#include<iostream>
#include"sort.h"

using namespace std;

int HeapSort(int* a, int n)
{
	BuildMaxHeap(a, n);

	int heapSize = n;
	for (int i = n; i > 0; i--)//" > 0 "
	{
		int tem = a[0];
		a[0] = a[heapSize - 1];
		a[heapSize - 1] = tem;
		heapSize--;
		MaxHeapify(a, 0, heapSize);
	}
	return 0;
}

int MaxHeapify(int* a, int i, int n)
{
	int largest = i;
	int l = Left(i);
	int r = Right(i);
	if (l < n && a[l] > a[i])
	{
		largest = l;
	}
	else
	{
		largest = i;
	}
	if (r < n && a[r] > a[largest])
	{
		largest = r;
	}
	if (largest != i)
	{
		int tem = a[i];
		a[i] = a[largest];
		a[largest] = tem;
		MaxHeapify(a, largest, n);
	}
	return 0;
}

int BuildMaxHeap(int* a, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)//" >= 0 "
	{
		MaxHeapify(a, i, n);
	}
	return 0;
}

int Parent(int i)
{
	return ((i - 1) / 2);
}

int Left(int i)
{
	return (2 * i + 1);
}

int Right(int i)
{
	return (2 * i + 2);
}