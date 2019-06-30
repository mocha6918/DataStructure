#include<iostream>
using namespace std;


void ShellSort(int* a, int n)
{
	for (int d = n / 2; d > 0; d /= 2)//增量序列
	{
		int i;
		for (int j = d; j < n; j++)
		{
			int key;//抽的卡
			key = a[j];
			for (i = j; i >= d && a[i - d] > key; i -= d)
			{
				a[i] = a[i - d];//留空位
			}
			a[i] = key;//此时i是最顶头的一位了
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	ShellSort(a, n);
	//BubbleSort(a, n);
	//InsertSort(a, n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
	delete[] a;
}
