#include<iostream>
using namespace std;
//这是递归的归并排序
/* L = 左边起始位置, R = 右边起始位置, RightEnd = 右边终点位置*/
void Merge(int* a, int* tempa, int L, int R, int RightEnd)
{
	/* 将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个有序序列 */
	int LeftEnd, NumElements, Tmp;
	int i;

	LeftEnd = R - 1; /* 左边终点位置 */
	Tmp = L;         /* 有序序列的起始位置 */
	NumElements = RightEnd - L + 1;

	while (L <= LeftEnd && R <= RightEnd) {
		if (a[L] <= a[R])
			tempa[Tmp++] = a[L++]; /* 将左边元素复制到tempa */
		else
			tempa[Tmp++] = a[R++]; /* 将右边元素复制到tempa */
	}

	while (L <= LeftEnd)
		tempa[Tmp++] = a[L++]; /* 直接复制左边剩下的 */
	while (R <= RightEnd)
		tempa[Tmp++] = a[R++]; /* 直接复制右边剩下的 */

	for (i = 0; i < NumElements; i++, RightEnd--)
		a[RightEnd] = tempa[RightEnd]; /* 将有序的tempa[]复制回A[] */
}

void Msort(int* a, int* tempa, int L, int RightEnd)
{
	//核心
	int center;
	if (L < RightEnd)
	{
		center = (L + RightEnd) / 2;
		Msort(a, tempa, L, center);              /* 递归解决左边 */
		Msort(a, tempa, center + 1, RightEnd);     /* 递归解决右边 */
		Merge(a, tempa, L, center + 1, RightEnd);  /* 合并两段有序序列 */
	}

}

void MergeSort(int* a, int n)
{
	//申请和a长度一样的临时数组
	int* tempa = (int*)malloc(n * sizeof(int));
	if (tempa != NULL)
	{
		Msort(a, tempa, 0, n - 1);
		free(tempa);
	}
	else cout << "空间不足";
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
