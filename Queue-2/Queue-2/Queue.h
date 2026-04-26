#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDatatype;

//定义Queue
typedef struct QListNode
{
	struct QListNode* next;
	QDatatype val;
}QNode;

typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;

//初始化
void QueueInit(Queue* pq);

//入队
void QueuePush(Queue* pq, QDatatype x);

//出队
void QueuePop(Queue* pq);

//获取队头元素
QDatatype QueueFront(Queue* pq);

//获取队尾元素
QDatatype QueueBack(Queue* pq);

//获取队列中有效元素个数
int QueueSize(Queue* pq);

//检测队列是否为空
bool QueueEmpty(Queue* pq);

//销毁队列
void QueueDestroy(Queue* pq);