#pragma once
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;

//定义栈结构体
typedef struct stack
{
	STDataType* a; //动态数组
	int top;       //栈顶
	int capacity;  //容量
}Stack;

//初始化
void StackInit(Stack* ps);

//入栈
void StackPush(Stack* ps, STDataType x);

//出栈
void StackPop(Stack* ps);

//获取栈顶元素
STDataType StackTop(Stack* ps);

//获取栈中有效元素个数
int StackSize(Stack* ps);

//检测栈是否为空
bool StackEmpty(Stack* ps);

//销毁栈
void StackDestroy(Stack* ps);