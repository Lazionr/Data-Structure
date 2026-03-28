#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SList
{
	int data;
	struct SList* next;
}SLTNode;

void SLTprint(SLTNode* phead);

void SLTPushBack(SLTNode** pphead, SLDataType x);

void SLTPushFront(SLTNode** pphead, SLDataType x);

void SLTPopBack(SLTNode** pphead);

void SLTPopFront(SLTNode** pphead);

SLTNode* SLTFind(SLTNode* phead, SLDataType x);

//在指定位置之前插入数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLDataType x);

//在指定位置之后插入数据
void SLTInsertAfter(SLTNode* pos, SLDataType x);

//删除pos节点
void SLTErase(SLTNode** pphead,SLTNode* pos);

//删除pos之后的节点
void SLTEraseAfter(SLTNode* pos);

//销毁链表
void SListDestroy(SLTNode** pphead);