#include "Heap.h"

void HeapSort(int* a, int n)
{
	//建堆
	//思路一
	//for (int i = 1; i < n; i++)
	//{
	//	AdjustUp(a, i);
	//}
	//思路二
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	//排序
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}




int main()
{
	HP hp;

	HPInit(&hp);

	HPPush(&hp, 1);
	HPPush(&hp, 2);
	HPPush(&hp, 3);
	HPPush(&hp, 4);
	HPPush(&hp, 5);
	HPPush(&hp, 6);
	HPPush(&hp, 7);

	printf("堆的元素个数：%d\n", HPSize(&hp));

	while (!HPEmpty(&hp))
	{
		printf("%d ", HPTop(&hp));
		HPPop(&hp);
	}

	HPDestroy(&hp);


	//int arr[] = { 12,46,78,23,75,98,26,67,54,32 };
	//int sz = sizeof(arr) / sizeof(int);
	//HeapSort(arr,sz);
	//for (int i = 0; i < sz; i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	//printf("\n");
	

	return 0;
}