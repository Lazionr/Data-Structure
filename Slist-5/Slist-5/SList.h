#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDataType;

typedef struct SListNode 
{
	SLDataType data;
	struct SListNode* next;	
}SLTNode;


//1.尾插
void SLTPushBack(SLTNode** pphead,SLDataType x);

//2.打印
void SLTPrint(SLTNode* pphead);

//3.头插
void SLTPushFront(SLTNode** pphead, SLDataType x);

//4.尾删
void SLTPopBack(SLTNode** pphead);

//5.头删
void SLTPopFront(SLTNode** pphead);

//6.查找
SLTNode* SLTFind(SLTNode* phead, SLDataType x);

//7.在指定位置之前插入
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLDataType x);

//8.删除pos节点
void SLTErase(SLTNode** pphead, SLTNode* pos);

//9.在指定位置之后插入
void SLTInsertAfter(SLTNode* pos, SLDataType x);

//10.删除pos之后的节点
void SLTEraseAfter(SLTNode* pos);

//11.销毁链表
void SLTDestroy(SLTNode** pphead);