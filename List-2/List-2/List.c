#include "List.h"

//申请节点
LTNode* LTBuyNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc failed!\n");
		exit(1);
	}
	newnode->val = x;
	//循环链表需要将自身的next和prev指向自身
	newnode->next = newnode->prev = newnode;

	return newnode;
}

//初始化
void LTInit(LTNode** pphead)
{
	//申请哨兵位
	*pphead = LTBuyNode(-1);
}

//打印
void LTPrint(LTNode* phead)
{
	//从有效数据开始遍历
	if (phead == NULL)
	{
		printf("链表已经被销毁！\n");
		return;
	}
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}


//尾插
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	//申请节点
	LTNode* newnode = LTBuyNode(x);
	//找到尾节点
	LTNode* tail = phead->prev;
	//先修改自身的节点
	newnode->prev = tail;
	newnode->next = phead;
	//再修改指向自身的节点
	//因为是在末尾节点之后插入，因此最后修改末尾节点的后驱
	phead->prev = newnode;
	tail->next = newnode;
}

//头插
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	//申请节点
	LTNode* newndoe = LTBuyNode(x);
	//先修改自身指向
	newndoe->prev = phead;
	newndoe->next = phead->next;
	//再修改指向自身的节点
	//最后修改头指针的后驱
	phead->next->prev = newndoe;
	phead->next = newndoe;
}

//尾删
void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	//找到尾节点
	LTNode* tail = phead->prev;
	LTNode* prevtail = tail->prev;
	free(tail);
	tail = NULL;
	phead->prev = prevtail;
	prevtail->next = phead;
}

//头删
void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LTNode* del = phead->next;
	LTNode* next = del->next;
	free(del);
	del = NULL;
	phead->next = next;
	next->prev = phead;
}

//查找
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	assert(phead->next);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->val == x) return cur;
		cur = cur->next;
	}
	return NULL;
}

//在pos之前插入
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	//先申请节点
	LTNode* newnode = LTBuyNode(x);
	//先修改自身节点的指向
	newnode->next = pos;
	newnode->prev = pos->prev;
	//最后修改pos的前驱
	pos->prev->next = newnode;
	pos->prev = newnode;
}

//删除pos节点
void LTErase(LTNode* pos)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;
	free(pos);
	pos = NULL;
	prev->next = next;
	next->prev = prev;
}

//销毁
void LTDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}