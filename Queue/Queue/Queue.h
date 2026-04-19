#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDataType;

typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;

//在顺序存储结构（如数组、动态数组实现的顺序队列）中
//内存是连续分配的，两个指针（或下标）相减的结果就是它们之间元素的个数
//在链表实现的队列中不能用两个指针相减得到元素个数，存储非连续性

//单链表只使用一个指针是因为就算使用两个指针也解决不了尾删的问题
//尾删需要倒数第二个节点
//队列中使用两个节点正好解决出队的问题
//出队就是free(phead)


////入队 出队
//void QueuePush(QNode** pphead, QNode** pptail,QDataType x);
//void QueuePop(QNode** pphead, QNode** pptail);

//初始化
void QueueInit(Queue* pq);
//销毁
void QueueDestroy(Queue* pq);

//入队 出队
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);

//队列元素个数
int QueueSize(Queue* pq);

//队头元素
QDataType QueueFront(Queue* pq);

//队尾元素
QDataType QueueBack(Queue* pq);

//判空
bool QueueEmpty(Queue* pq);