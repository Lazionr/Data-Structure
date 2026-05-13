#include "Sort.h"

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		//单趟排序
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else break;
		}
		a[end + 1] = tmp;
	}
}

void BubbleSort(int* a, int n)
{
	for(int j = 0;j < n;j++)
	{
		//单趟排序
		int flag = false;
		for (int i = 1; i < n - j; i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				flag = true;
			}
		}
		if (flag == false) break;
	}
}


void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child]) child++;
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else break;
	}
}

void HeapSort(int* a, int n)
{
	//1.建堆
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a,n,i);
	}
	//2.排序
	for (int i = n - 1; i > 0; i--)
	{
		Swap(&a[0], &a[i]);
		AdjustDown(a, i, 0);
	}
}