#include<iostream>
using namespace std;

void swap(int* a, int x, int y)
{
	int temp = a[y];
	a[y] = a[x];
	a[x] = temp;
}
void adjustHeap(int* a, int i, int length)
{
	//�ѵ�ǰԪ�أ�����ȡ��,��Ϊ��ǰԪ�ؿ���һֱ�ƶ�
	int temp = a[i];
	//k��ֵ�Ǵ��ϵ��µ�
	for (int k = 2 * i + 1; k < length; k = 2 * k + 1)
	{
		//���k�������ӽڵ�,��kָ���ӽڵ��е����
		//(k���ӽڵ㣬k+1���ӽڵ�,���ڵ����Ƚ�)k+1<length�ж��Ƿ����ҽڵ�
		if (k + 1 < length && a[k] < a[k + 1])
		{
			k++;
		}
		//����ӽڵ���󣬾ͽ���
		if (a[k] > temp)
		{
			swap(a, i, k);
			// ����ӽڵ�����ˣ���ô�����ӽڵ�Ϊ���������᲻���ܵ�Ӱ���أ�
			// ѭ�����ӽڵ����ڵ������������ж�
			i = k;
		}
		//���ý��������Ѿ������ѣ�����ѭ����
		else break;
	}

}

void sort(int* a, int length)
{
	//��Ϊ������ȫ�����������һ����Ҷ�ӽڵ����length/2��������Ϊ��������洢�ģ��±��0��ʼ��������length/2-1
	//�Ǵ������濪ʼ���������ѣ��������������Ǵ��ҵ����
	//���ѣ����µ��ϴ��ҵ������
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		adjustHeap(a, i, length);
	}
	//��ʼ���������Ǵ��ϵ��´����ҵĵ���
	for (int j = length - 1; j > 0; j--)
	{
		//�����ѵĸ��ڵ�ŵ���󣬾��ǰ����ֵ�ŵ������
		swap(a, 0, j);
		//�����󣬿��ܶѵ�˳�����ˣ�Ҫ����������
		//���һ��ȥ����Ԫ�ؾͲ��ÿ���������
		//���ϵ��£������ҵĵ���
		adjustHeap(a, 0, j);
	}
}



int main()
{
	int length;
	cin >> length;
	int* a = new int[length];
	for (int i = 0; i < length; i++)
	{
		cin >> a[i];
	}
	sort(a, length);
	for (int i = 0; i < length; i++)
	{
		cout << a[i] << " ";
	}
	delete[] a;

}
