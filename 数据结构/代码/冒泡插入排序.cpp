#include<iostream>
using namespace std;
void swap(int* a, int* b)
{
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}

void BubbleSort(int* a, int n)
{
	int count = 0;
	for (int p = n - 1; p >= 0; p--)
	{
		int flag = 0;
		for (int j = 0; j < p; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				count++;
			}
			flag = 1;
		}
		if (flag == 0) break;
	}
	cout << count;
}

void InsertSort(int* a, int n)
{
	int i;
	for (int j = 1; j < n; j++)
	{
		int key;//抽的卡
		key = a[j];
		//每次排序一个数key，都要对比前面的对比该位置的值与该位置前面的值的大小，若key较小，则将与key对比的数往后移动一位。
		for (i = j; i > 0 && a[i - 1] > key; i--)
		{
			a[i] = a[i - 1];//留空位
		}
		a[i] = key;//此时i是最顶头的一位了
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
	BubbleSort(a, n);
	//InsertSort(a, n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
	delete[] a;
}
