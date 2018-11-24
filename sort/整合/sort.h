#pragma once
void insert_sort(int ar[], int n);//插入排序
void merge_sort(int * a, int p, int r);//归并排序
	void merge_sort(int * a, int p, int r, int *t);//归并排序-附求逆序数t
void bubble_sort(int* a, int n);//冒泡排序
void search_sort(int * a, int n);//选择排序
int HeapSort(int* a, int n);//堆排序
void QuickSort(int * a, int p, int r);//快速排序
void CountSort(int * a, int n);//计数排序
void RadixSort(int * a, int n, int maxBit);//基数排序



void merge(int * a, int p, int q, int r);//归并
void merge(int * a, int p, int q, int r, int *t);//归并-附求逆序数t

//int HeapSort(int* a, int n);//堆排序
int MaxHeapify(int* a, int i, int n);//维护堆性质
int BuildMaxHeap(int* a, int n);//建堆
int Parent(int i);
int Left(int i);
int Right(int i);

int Partition(int * a, int p, int r);//原址重排-快速排序

int MaxNum(int  * a, int n);

//用于基数排序
bool lessCpr(int x, int y, int bit);

