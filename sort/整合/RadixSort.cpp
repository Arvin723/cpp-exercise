#include<iostream>
#include<cmath>
#include"sort.h"

void RadixSort(int * a, int n, int maxBit)
{
	for (int k = 1; k <= maxBit; k++)
	{
		//使用一个稳定的排序，此处应使用时间复杂度小的
		//暂使用插入排序（这将导致运行时间很长）
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

//按位比较是否小于
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