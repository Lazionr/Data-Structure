#include "Stack.h"

//初始化 销毁
void STInit(ST* pst)
{
	assert(pst);
	pst->a = NULL;

	//指向栈顶
	//pst->top = -1;
	//指向栈顶的下一个位置
	//此时和顺序表中size作用一致
	pst->top = 0;

	pst->capacity = 0;
}

void STDestroy(ST* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
}

//入栈 出栈
void STPush(ST* pst, STDataType x)
{
	assert(pst);
	//top指向栈顶的下一个位置
	if (pst->top == pst->capacity)
	{
		//扩容
		int newcapacity = pst->capacity == 0 ? 4 : 2 * pst->capacity;
		//realloc 如果第一个参数是NULL，此时就是malloc
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc failed!\n");
			return;
		}
		pst->a = tmp;
		pst->capacity = newcapacity;
	}
	pst->a[pst->top] = x;
	pst->top++;
}
void STPop(ST* pst)
{
	assert(pst);
	pst->top--;
}

//获取栈顶数据
STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);

	return pst->a[pst->top - 1];
}

//判空
bool STEmpty(ST* pst)
{
	assert(pst);
	return pst->top == 0;
}

//获取元素个数
int STSize(ST* pst)
{
	assert(pst);
	return pst->top;
}
