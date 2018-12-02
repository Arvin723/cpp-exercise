#include<iostream>
#include<cstdlib>
//#include<time.h>
#include<ctime>

using namespace std;


/*将数组a中的元素随机排列*/
void RandomizeInPlace(int * a, int n);

int main()
{
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	RandomizeInPlace(a, 10);
	for (int i = 0; i < 10; i++)
	{
		cout<<a[i]<<' ';
	}
	cout<<'\n';
}

void RandomizeInPlace(int * a, int n)
{
	int tmp;
	int m;
	time_t t;
	time(&t);
	for (int i = 0; i < n; i++)
	{
		srand(i+t);
		m = rand()%(n-i) + i;
		tmp = a[i];
		a[i] = a[m];
		a[m] = tmp;
	}
}