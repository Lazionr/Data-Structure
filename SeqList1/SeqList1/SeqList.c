#include "SeqList.h"

//初始化
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}
//检查空间
void SLCheckCapacity(SL* ps)
{
	assert(ps);
	//插入之前判断空间够不够
	if (ps->size == ps->capacity)
	{
		//判断是否为0
		int Newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		//扩大两倍
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, Newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			//申请失败
			perror("realloc failed!");
			exit(1);
		}
		//此时开辟成功
		ps->arr = tmp;
		ps->capacity = Newcapacity;
	}
}
//void SLshow(SL s)
//{
//	for (int i = 0; i < s.size; i++)
//	{
//		printf("%d ", s.arr[i]);
//	}
//}
//尾插
void SLPushBack(SL* ps, SLDataType x)
{
	SLCheckCapacity(ps);
	//插入
	ps->arr[ps->size++] = x;
}
//头插
void SLPushFront(SL* ps, SLDataType x)
{
	SLCheckCapacity(ps);
	//插入	
	//1.先将元素向后移
	for (int i = ps->size - 1; i >= 0; i--)
	{
		ps->arr[i + 1] = ps->arr[i];
	}
	//2.头插
	ps->arr[0] = x;
	//3.更新size
	ps->size++;
}
//尾删
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size);
	ps->size--;
}
//头删
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size);
	//将后面元素向前挪动一位即可，size--
	for (int i = 1; i < ps->size; i++)
	{
		ps->arr[i - 1] = ps->arr[i];
	}
	ps->size--;
}
//任意位置之前插入
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(0 <= pos <= ps->size);
	SLCheckCapacity(ps);
	//将pos及以后的位置后移
	for (int i = ps->size - 1;i >= pos; i--)
	{
		ps->arr[i + 1] = ps->arr[i];
	}
	ps->arr[pos] = x;
	ps->size++;
}
//任意位置删除元素
void SLErase(SL* ps,int pos)
{
	assert(ps);
	assert(ps->size);
	assert(0 <=  pos < ps->size);
	//将pos后面的元素向前挪动一位
	for (int i = pos + 1; i < ps->size; i++)
	{
		ps->arr[i - 1] = ps->arr[i];
	}
	ps->size--;
}
////查找
//int SLFind(SL* ps, SLDataType x)
//{
//	for (int i = 0; i < ps->size; i++)
//	{
//		if (ps->arr[i] == x) return i;
//	}
//	return -1;
//}
//销毁
void SLDestroy(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}