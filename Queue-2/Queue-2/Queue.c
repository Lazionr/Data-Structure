#include "Queue.h"

//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	//在获取队列中有效元素个数中说明size
	pq->size = 0;
}

//入队
void QueuePush(Queue* pq, QDatatype x)
{
	assert(pq);
	//申请节点
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{	
		perror("malloc failed!\n");
		return;
	}
	newnode->val = x;
	newnode->next = NULL;

	if (pq->ptail == NULL)
	{
		//第一个入队元素
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		//直接在队尾插入
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	//在获取队列中有效元素个数中说明size
	pq->size++;
}

//出队
void QueuePop(Queue* pq)
{
	assert(pq);
	//队列不能为空
	assert(pq->size > 0);
	QNode* next = pq->phead->next;
	free(pq->phead);
	pq->phead = next;
	if (pq->phead == NULL)
	{
		pq->ptail = NULL;
	}
	//在获取队列中有效元素个数中说明size
	pq->size--;
}

//获取队头元素
QDatatype QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->phead);
	return pq->phead->val;
}

//获取队尾元素
QDatatype QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->ptail);
	return pq->ptail->val;
}

//获取队列中有效元素个数
int QueueSize(Queue* pq)
{
	//不能直接用尾指针 - 头指针
	//两个指针并非顺序存储
	assert(pq);
	return pq->size;	
}

//检测队列是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	//return pq->phead == NULL;
	//在获取队列中有效元素个数中说明size
	return pq->size == 0;
}

//销毁队列
void QueueDestroy(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
