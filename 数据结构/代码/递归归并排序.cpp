#include<iostream>
using namespace std;
//���ǵݹ�Ĺ鲢����
/* L = �����ʼλ��, R = �ұ���ʼλ��, RightEnd = �ұ��յ�λ��*/
void Merge(int* a, int* tempa, int L, int R, int RightEnd)
{
	/* �������A[L]~A[R-1]��A[R]~A[RightEnd]�鲢��һ���������� */
	int LeftEnd, NumElements, Tmp;
	int i;

	LeftEnd = R - 1; /* ����յ�λ�� */
	Tmp = L;         /* �������е���ʼλ�� */
	NumElements = RightEnd - L + 1;

	while (L <= LeftEnd && R <= RightEnd) {
		if (a[L] <= a[R])
			tempa[Tmp++] = a[L++]; /* �����Ԫ�ظ��Ƶ�tempa */
		else
			tempa[Tmp++] = a[R++]; /* ���ұ�Ԫ�ظ��Ƶ�tempa */
	}

	while (L <= LeftEnd)
		tempa[Tmp++] = a[L++]; /* ֱ�Ӹ������ʣ�µ� */
	while (R <= RightEnd)
		tempa[Tmp++] = a[R++]; /* ֱ�Ӹ����ұ�ʣ�µ� */

	for (i = 0; i < NumElements; i++, RightEnd--)
		a[RightEnd] = tempa[RightEnd]; /* �������tempa[]���ƻ�A[] */
}

void Msort(int* a, int* tempa, int L, int RightEnd)
{
	//����
	int center;
	if (L < RightEnd)
	{
		center = (L + RightEnd) / 2;
		Msort(a, tempa, L, center);              /* �ݹ������ */
		Msort(a, tempa, center + 1, RightEnd);     /* �ݹ����ұ� */
		Merge(a, tempa, L, center + 1, RightEnd);  /* �ϲ������������� */
	}

}

void MergeSort(int* a, int n)
{
	//�����a����һ������ʱ����
	int* tempa = (int*)malloc(n * sizeof(int));
	if (tempa != NULL)
	{
		Msort(a, tempa, 0, n - 1);
		free(tempa);
	}
	else cout << "�ռ䲻��";
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
	MergeSort(a, n);

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	delete[] a;

}
