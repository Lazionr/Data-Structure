#pragma once
#include "Contact.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef PeoInfo SLDatatype;

typedef struct SeqList
{
	SLDatatype* arr;  
	int size;         //有效数据个数
	int capacity;     //空间容量
}SL;

//初始化
void SLInit(SL* ps);

//打印
void SLPrint(SL* ps);

//尾插
void SLPushBack(SL* ps, SLDatatype x);

//头插
void SLPushFront(SL* ps, SLDatatype x);

//尾删
void SLPopBack(SL* ps);

//头删
void SLPopFront(SL* ps);

//在指定位置之前插入
void SLInsert(SL* ps, int pos, SLDatatype x);

//删除任意位置
void SLErase(SL* ps,int pos);

//查找任意位置
int SLFind(SL* ps, SLDatatype x);

//销毁
void SLDestroy(SL* ps);