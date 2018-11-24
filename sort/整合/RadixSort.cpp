#include<iostream>
#include<cmath>
#include"sort.h"

void RadixSort(int * a, int n, int maxBit)
{
	for (int k = 1; k <= maxBit; k++)
	{
		//ʹ��һ���ȶ������򣬴˴�Ӧʹ��ʱ�临�Ӷ�С��
		//��ʹ�ò��������⽫��������ʱ��ܳ���
		///*insert sort
		int key = 0;
		for (int i = 1; i< n; i++)
		{
			key = a[i];
			int j = i;
			while (j > 0)
			{
				//if (key < a[j - 1])
				if (lessCpr(key, a[j - 1], k))
				{
					a[j] = a[j - 1];
				}
				else
				{
					break;
				}
				j--;
			}
			a[j] = key;
		}
		//*/


	}
}

//��λ�Ƚ��Ƿ�С��
bool lessCpr(int x, int y, int bit)
{
	if (bit == 1)
	{
		x = x % 10;
		y = y % 10;
		return x < y ? true : false;
	}
	else
	{
		x = (x / (int)pow(10, (bit - 1))) % 10;
		y = (y / (int)pow(10, (bit - 1))) % 10;
		return x < y ? true : false;
	}
}