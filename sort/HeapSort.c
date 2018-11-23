#include<stdio.h>

int HeapSort(int* a, int n);//堆排序
int MaxHeapify(int* a, int i, int n);//维护堆性质
int BuildMaxHeap(int* a, int n);//建堆

int Parent(int i);
int Left(int i);
int Right(int i);

int main()
{
	int a[15] = {1, 8, 3, 6, 7, 5, 4, 2, 10, 9, 0, 14, 13 ,11, 12};
	HeapSort(a, 15);
	for (int i = 0; i < 15; i++)
	{
		printf("%d ",a[i]);
	}
}

int HeapSort(int* a, int n)
{
	//printf("********BuildMaxHeap begin********\n");
	BuildMaxHeap(a, n);
	//printf("********BuildMaxHeap end  ********\n");
	
	//printf("********HeapSort begin********\n");
	int heapSize = n;
	for (int i = n; i > 0; i-- )//" > 0 "
	{
		int tem = a[0];
		a[0] = a[heapSize-1];
		a[heapSize-1] = tem;
		heapSize--;
		MaxHeapify(a, 0, heapSize);
	}
	//printf("********HeapSort end  ********\n");
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
	
	/*
	for (int i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	*/
}

int BuildMaxHeap(int* a, int n)
{
	for (int i = n/2-1; i >= 0; i--)//" >= 0 "
	{
		MaxHeapify(a, i, n);
	}
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