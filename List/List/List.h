#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	LTDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}LTNode;

//初始化
//void LTInit(LTNode** pphead);
LTNode* LTInit();

//打印
void LTPrint(LTNode* phead);

//头插
void LTPushFront(LTNode* phead, LTDataType x);

//尾插
void LTPushBack(LTNode* phead, LTDataType x);

//头删
void LTPopFront(LTNode* phead);

//尾删
void LTPopBack(LTNode* phead);

//查找
LTNode* LTFind(LTNode* phead, LTDataType x);

//在pos位置之后插入元素
void LTInsert(LTNode* pos,LTDataType x);

//删除
void LTErase(LTNode* pos);

//销毁
void LTDestroy(LTNode* phead);