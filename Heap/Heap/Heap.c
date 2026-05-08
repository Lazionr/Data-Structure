#include "Heap.h"

//初始化
void HPInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->size = php->capacity = 0;
}

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//向上调整算法
void AdjustUp (HPDataType* a, int child)
{
	//仅对x判断，如果不符合条件直接跳出循环，不需要再往上走
	int parent = (child - 1) / 2;
	while (child)
	{
		//如果循环条件是 parent >= 0 当parent = child = 0时;
		//进入循环，此时a[child] < a[parent],循环结束

		//如果循环条件是 child > 0;当 child = 0 ，即child走到堆顶时，已经调整完毕，循环结束
		if (a[child] > a[parent])
		{
			//交换
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else break;
	}
}

//向下调整算法
void AdjustDown(HPDataType* a, int n,int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//找最大孩子
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}
		
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else break;
	}
}

//堆的插入
void HPPush(HP* php, HPDataType x)
{
	assert(php);
	//判断空间够不够
	if (php->capacity == php->size)
	{
		int newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc failed!\n");
			return;
		}
		php->a = tmp;
		php->capacity = newcapacity;
	}
	php->a[php->size++] = x;
	//进行向上调整算法
	AdjustUp(php->a, php->size - 1);
	
}

//堆的删除
void HPPop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	//1.堆顶元素先与末尾元素交换
	Swap(&php->a[php->size - 1], &php->a[0]);
	//2.删除末尾元素
	php->size--;
	//3.进行向下调整算法
	AdjustDown(php->a, php->size, 0);
}

//取堆顶数据
HPDataType HPTop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	return php->a[0];
}

//堆的数据个数
int HPSize(HP* php)
{
	assert(php);
	return php->size;
}

//堆的判空
bool HPEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}

//堆的销毁
void HPDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}