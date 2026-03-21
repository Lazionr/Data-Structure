#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//定义节点结构

typedef int SLDataType;

typedef struct SListNode
{
	int data;
	struct SListNode* next;
}SLTNode;

//打印
void SLTPrint(SLTNode* phead);
//尾插
void SLTPushBack(SLTNode** pphead, SLDataType x);
//头插
void SLTPushFront(SLTNode** pphead, SLDataType x);
//尾删
void SLTPopBack(SLTNode** pphead);
//头删
void SLTPopFront(SLTNode** pphead);
//查找
SLTNode* SLTFind(SLTNode* phead, SLDataType x);
//在指定位置之前插入数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLDataType x);
//在指定位置之后插入数据
void SLTInsertAfter(SLTNode* pos, SLDataType x);
//删除pos节点
void SLTErase(SLTNode** pphead, SLTNode* pos);
//删除pos之后的节点
void SLTEraseAfter(SLTNode* pos);
//销毁链表
void SListDestroy(SLTNode** pphead);
