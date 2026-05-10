#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//动态数组实现堆
typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int capacity;
	int size;
}HP;

//初始化
void HPInit(HP* php);

//向上调整算法
void AdjustUp(HPDataType* a, int child);

//堆的插入
void HPPush(HP* php, HPDataType x); 

//向下调整算法
void AdjustDown(HPDataType* a, int n, int parent);

//堆的删除
void HPPop(HP* php);

//获取堆顶元素
HPDataType HPTop(HP* php);

//获取堆的元素个数
int HPSize(HP* php);

//判断堆是否为空
bool HPEmpty(HP* php);

//销毁堆
void HPDestroy(HP* php);