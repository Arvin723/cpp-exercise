#include<stdio.h>

#define BuildMaxHeap BuildMaxPriorityQueue//����MaxHeapΪMaxPriorityQueue
#define MAXNUN 100//MaxPriorityQueue��size��仯�����趨���ֵ


int Insert(int* a, int* n, int key);//��Ԫ��x���뵽MaxPriorityQueue
int MaxImum(int* a, int n);//����MaxPriorityQueue�е����ֵ
int ExtractMax(int* a, int *n);//ȥ��������MaxPriorityQueue�е����ֵ
int IncreaseKey(int* a, int n, int i, int key);//��Ԫ��i�Ĺؼ�ֵ������key


int MaxHeapify(int* a, int i, int n);//ά��������
int BuildMaxHeap(int* a, int n);//����

int Parent(int i);
int Left(int i);
int Right(int i);

int main()
{
	int a[MAXNUN] = {1, 8, 3, 6, 7, 5, 4, 2, 10, 9, 0, 14, 13 ,11, 12};
	int n = 15;
	BuildMaxPriorityQueue(a, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	
	printf("MaxImum:%d\n",MaxImum(a,n));//MaxImum
	printf("ExtractMax:%d\n",ExtractMax(a, &n));//ExtractMax
	printf("	");
	for (int i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	printf("IncreaseKey:%d\n",IncreaseKey(a, n, 5, 15));//IncreaseKey
	printf("	");
	for (int i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	printf("Insert:%d\n",Insert(a, &n, 14));//Insert
	printf("	");
	for (int i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	
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

/***************** MaxPriorityQueue **********************************/
int Insert(int* a, int* n, int key)//n����ַ
{
	(*n)++;
	a[*n-1] = key;
	
	int i = *n-1;
	/*loop is same as IncreaseKey*/
	while(a[i] > a[Parent(i)] && i > 0)
	{
		int tem = a[i];
		a[i] = a[Parent(i)];
		a[Parent(i)] = tem;
		i = Parent(i);
	}
	/*loop is same as IncreaseKey*/
	return a[i];
}

int MaxImum(int* a, int n)
{
	return a[0];
}

int ExtractMax(int* a, int *n)//n����ַ
{
	if (*n < 1)
	{
		printf("heap underflow\n");
		return -1;
	}
	int ret = a[0];
	a[0] = a[(*n)-1];
	(*n)--;
	MaxHeapify(a, 0, *n);
	return ret;
}

int IncreaseKey(int* a, int n, int i, int key)
{
	if (key < a[i])
	{
		printf("new key is smaller then current key");
		return a[i];
	}
	a[i] = key;
	while(a[i] > a[Parent(i)] && i > 0)
	{
		int tem = a[i];
		a[i] = a[Parent(i)];
		a[Parent(i)] = tem;
		i = Parent(i);
	}
	printf("%d",i);
	return a[i];
}
/***************** MaxPriorityQueue **********************************/