#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HPDataType;

//堆的本质是完全二叉树

//默认实现大根堆

//顺序存储
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

//初始化
void HPInit(HP* php);

//堆的插入
void HPPush(HP* php, HPDataType x);

//堆的删除
void HPPop(HP* php);

//取堆顶数据
HPDataType HPTop(HP* php);

//堆的数据个数
int HPSize(HP* php);

//堆的判空
bool HPEmpty(HP* php);

//堆的销毁
void HPDestroy(HP* php);
