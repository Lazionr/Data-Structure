#include "List.h"

LTNode* LTBuyNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));

	if (node == NULL)
	{
		perror("malloc failed!\n");
		exit(1);
	}
	
	node->data = x;
	node->prev = node->next = node;

	return node;
}

//初始化
//void LTInit(LTNode** pphead)
//{
//	//申请哨兵位
//	*pphead = LTBuyNode(-1);
//
//}

LTNode* LTInit()
{
	LTNode* phead = LTBuyNode(-1);
	return phead;
}


//打印
void LTPrint(LTNode* phead)
{
	LTNode* pcur = phead->next;

	while (pcur != phead)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}

//头插
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(x);

	//在任意位置之前插入，最后修改p的前驱
	//在任意位置之后插入，最后修改p的后继
	newnode->next = phead->next;
	newnode->prev = phead;
	phead->next->prev = newnode;
	phead->next = newnode;

}

//尾插
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* newnode = LTBuyNode(x);

	LTNode* ptail = phead;

	//while (ptail->next != phead) ptail = ptail->next;

	//双向链表ptail就是phead->prev,无需循环
	//newnode->next = phead;
	//newnode->prev = ptail;
	//ptail->next = newnode;
	//phead->prev = newnode;

	//在任意位置之前插入，最后修改p的前驱
	//在任意位置之后插入，最后修改p的后继
	newnode->next = phead;
	newnode->prev = phead->prev;
	phead->prev->next = newnode;
	phead->prev = newnode;
}

//头删
void LTPopFront(LTNode* phead)
{
	//链表必须有效且链表不能为空
	assert(phead && phead->next != phead);

	LTNode* del = phead->next;

	phead->next = del->next;
	del->next->prev = phead;

	free(del);
	del = NULL;
}

//尾删
void LTPopBack(LTNode* phead)
{
	//链表必须有效且链表不能为空
	assert(phead && phead->next != phead);

	LTNode* del = phead->prev;

	del->prev->next = phead;
	phead->prev = del->prev;

	free(del);
	del = NULL;
}

//查找
LTNode* LTFind(LTNode* phead,LTDataType x)
{
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		if (pcur->data == x) return pcur;
		pcur = pcur->next;
	}
	return NULL;
}

//在pos位置之后插入元素
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = LTBuyNode(x);

	newnode->next = pos->next;
	newnode->prev = pos;
	pos->next->prev = newnode;
	pos->next = newnode;
}

//删除
void LTErase(LTNode* pos)
{
	//pos不能为phead
	assert(pos);

	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;

}

//销毁
void LTDestroy(LTNode* phead)
{
	assert(phead);

	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		//当pcur有效时才创建next指针
		LTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	free(phead);
	phead = NULL;

}