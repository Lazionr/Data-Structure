#include "SeqList.h"

//初始化
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
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

//自动扩容
void SLCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int Newcapacity = ps->size == 0 ? 4 : 2 * ps->capacity;
		SLDatatype* tmp = (SLDatatype*)realloc(ps->arr, Newcapacity * sizeof(SLDatatype));
		if (tmp == NULL)
		{
			perror("realloc failed!\n");
			exit(1);
		}
		//扩容成功
		ps->arr = tmp;
		ps->capacity = Newcapacity;
	}
}

//尾插
void SLPushBack(SL* ps, SLDatatype x)
{
	assert(ps);
	SLCheckCapacity(ps);
	ps->arr[ps->size++] = x;
}

//头插
void SLPushFront(SL* ps, SLDatatype x)
{
	assert(ps);
	SLCheckCapacity(ps);
	//将所有元素向后移动一位
	for (int i = ps->size - 1; i >= 0; i--)
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
	//从第二个元素开始均向前挪动一位
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i +	 1];
	}
	ps->size--;
}

//在指定位置之前插入
void SLInsert(SL* ps, int pos, SLDatatype x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SLCheckCapacity(ps);

	//将pos及其之后的元素全部向后移动一位
	for (int i = ps->size - 1;i >= pos; i--)
	{
		ps->arr[i + 1] = ps->arr[i];
	}
	ps->arr[pos] = x;
	ps->size++;

}

//删除任意位置
void SLErase(SL* ps,int pos)
{
	assert(ps);
	assert(ps->arr);
	assert(pos >= 0 && pos <= ps->size - 1);
	//将pos + 1及其后面元素向前挪动一位
	for (int i = pos + 1; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

////查找任意位置
//int SLFind(SL* ps, SLDatatype x)
//{
//	assert(ps->size);
//	for (int i = 0; i <= ps->size - 1; i++)
//	{
//		if (ps->arr[i] == x) return i;
//	}
//	return -1;
//}

//销毁
void SLDestroy(SL* ps)
{
	if(ps->arr) free(ps->arr);
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}