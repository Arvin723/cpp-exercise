#pragma once
void insert_sort(int ar[], int n);//��������
void merge_sort(int * a, int p, int r);//�鲢����
	void merge_sort(int * a, int p, int r, int *t);//�鲢����-����������t
void bubble_sort(int* a, int n);//ð������
void search_sort(int * a, int n);//ѡ������
int HeapSort(int* a, int n);//������
void QuickSort(int * a, int p, int r);//��������
void CountSort(int * a, int n);//��������
void RadixSort(int * a, int n, int maxBit);//��������



void merge(int * a, int p, int q, int r);//�鲢
void merge(int * a, int p, int q, int r, int *t);//�鲢-����������t

//int HeapSort(int* a, int n);//������
int MaxHeapify(int* a, int i, int n);//ά��������
int BuildMaxHeap(int* a, int n);//����
int Parent(int i);
int Left(int i);
int Right(int i);

int Partition(int * a, int p, int r);//ԭַ����-��������

int MaxNum(int  * a, int n);

//���ڻ�������
bool lessCpr(int x, int y, int bit);

