#include "Heap.h"

//初始化
void HPInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = php->size = 0;
}

void Swap(HPDataType* x, HPDataType* y)
{
	HPDataType tmp = *x;
	*x = *y;
	*y = tmp;
}

//向上调整算法
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			//更新节点
			child = parent;
			parent = (child - 1) / 2;
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
		//扩容
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

	//插入x
	php->a[php->size] = x;
	//size++
	php->size++;

	//向上调整算法
	AdjustUp(php->a, php->size - 1);
}

//向下调整算法
void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//找最大孩子
		if (child + 1 < n && a[child] < a[child + 1]) child++;
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else break;
	}
}

//堆的删除
void HPPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	//1.交换
	Swap(&php->a[0], &php->a[php->size - 1]);
	//2.删除最后一个元素
	php->size--;
	//3.向下调整
	AdjustDown(php->a, php->size, 0);
}

//获取堆顶元素
HPDataType HPTop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}

//获取堆的元素个数
int HPSize(HP* php)
{
	assert(php);
	return php->size;
}

//判断堆是否为空
bool HPEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}

//销毁堆
void HPDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->capacity = php->size = 0;
}