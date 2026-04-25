#include "Stack.h"

//初始化
void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

//入栈
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	//判断空间够不够
	if (ps->top == ps->capacity)
	{
		//申请空间
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		STDataType* newa = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);
		if (newa == NULL)
		{
			printf("realloc failed!\n");
			return;
		}
		ps->a = newa;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

//出栈
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}

//获取栈顶元素
STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->a[ps->top - 1];
}

//获取栈中有效元素个数
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}

//检测栈是否为空
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}

//销毁栈
void StackDestroy(Stack* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}