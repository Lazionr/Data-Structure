#include "SeqList.h"

//初始化
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}
////打印
//void SLPrint(SL* ps)
//{
//	for (int i = 0; i < ps->size; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	printf("\n");
//}
//检查空间够不够
void SLCheckCapacity(SL* ps)
{
	if (ps->capacity == ps->size)
	{
		int NewCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		//进行扩容
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, NewCapacity * sizeof(SLDataType));
		if (tmp != NULL)
		{
			//扩容成功
			ps->arr = tmp;
			ps->capacity = NewCapacity;
		}
		else
		{
			perror("realloc falied!");
			exit(1);
		}
	}
}
//尾插
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	//进行扩容
	SLCheckCapacity(ps);
	ps->arr[ps->size++] = x;
}
//头插
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	//进行扩容
	SLCheckCapacity(ps);
	for(int i = ps->size - 1; i >= 0; i--)
	{
		ps->arr[i + 1] = ps->arr[i];
	}
	ps->arr[0] = x;
	ps->size++;
}
//尾删
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);
	ps->size--;
}
//头删
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);
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
	SLCheckCapacity(ps);
	assert(pos >= 0 && pos <= ps->size);
	for (int i = ps->size - 1; i >= pos;i--)
	{
		ps->arr[i + 1] = ps->arr[i];
	}
	ps->arr[pos] = x;
	ps->size++;
}
//删除任意位置
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(ps->arr);
	assert(0 <= pos < ps->size);
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}
////查找任意位置
//int SLFind(SL* ps, SLDataType x)
//{
//	assert(ps->size);
//	for (int i = 1; i < ps->size; i++)
//	{
//		if (ps->arr[i] == x) return i;
//	}
//	return -1;
//}
//销毁
void SLDestroy(SL* ps)
{
	if (ps->arr != NULL)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}