#include<iostream>

using namespace std;

void insert_sort(int ar[], int n);

int main()
{
	int a[10] = {3, 1, 8, 2, 4, 9, 0, 5, 7, 6};
	insert_sort(a,10);
	for (int i = 0; i < 10; i++)
	{
		cout<<a[i];
		cout<<" ";
	}
	cout<<endl;
}

void insert_sort(int ar[], int n)
{
	int key = 0;
	for (int i = 1; i< n; i++)
	{
		key = ar[i];
		int j = i;
		while(j > 0)
		{
			if(key < ar[j-1])
			{
				ar[j] = ar[j-1];
			}
			else 
			{
				break ;
			}
			j--;
		}
		ar[j] = key;
	}
}