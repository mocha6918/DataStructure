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
		int key;//��Ŀ�
		key = a[j];
		//ÿ������һ����key����Ҫ�Ա�ǰ��ĶԱȸ�λ�õ�ֵ���λ��ǰ���ֵ�Ĵ�С����key��С������key�Աȵ��������ƶ�һλ��
		for (i = j; i > 0 && a[i - 1] > key; i--)
		{
			a[i] = a[i - 1];//����λ
		}
		a[i] = key;//��ʱi���ͷ��һλ��
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
