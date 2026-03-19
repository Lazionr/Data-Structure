#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include<string.h>
#include <stdlib.h>
#include "Contact.h"
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
//打印
void SLPrint(SL* ps);
//尾插
void SLPushBack(SL* ps, SLDataType x);
//头插
void SLPushFront(SL* ps, SLDataType x);
//尾删
void SLPopBack(SL* ps);
//头删
void SLPopFront(SL* ps);
//任意位置之前插入
void SLInsert(SL* ps, int pos, SLDataType x);
//删除任意位置
void SLErase(SL* ps, int pos);
//查找任意位置
int SLFind(SL* ps, SLDataType x);
//销毁
void SLDestroy(SL* ps);