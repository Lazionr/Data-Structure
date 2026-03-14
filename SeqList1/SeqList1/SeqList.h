#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Contact.h"
#include <string.h>
//更改顺序表类型
//typedef int SLDataType;
typedef PeoInfo SLDataType;

typedef struct SeqList
{
	SLDataType* arr;
	int size;
	int capacity;
}SL;

//初始化
void SLInit(SL* ps);
//销毁
void SLDestroy(SL* ps);
//检查空间
void SLCheckCapacity(SL* ps);
//尾插
void SLPushBack(SL* ps, SLDataType x);
//头插
void SLPushFront(SL* ps, SLDataType x);
//尾删
void SLPopBack(SL* ps);
//头删
void SLPopFront(SL* ps);
//打印
void SLshow(SL s);
//任意位置之前插入
void SLInsert(SL* ps, int pos, SLDataType x);
//任意位置删除元素
void SLErase(SL* ps,int pos);
//查找
int SLFind(SL* ps, SLDataType x);