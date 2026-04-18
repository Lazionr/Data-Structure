#include "SList.h"

//打印
void SLTPrint(SLTNode* pphead)
{
	SLTNode* cur = pphead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL");
	printf("\n");
}


//申请节点
SLTNode* SLTBuyNode(SLDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("SLTBuyNode::malloc\n");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//1.尾插
void SLTPushBack(SLTNode** pphead, SLDataType x)
{
	assert(pphead);

	//创建一个节点
	SLTNode* newnode = SLTBuyNode(x);

	if (*pphead == NULL)
	{
		//空链表
		*pphead = newnode;
	}
	else
	{
		//非空链表
		//1.找尾节点
		SLTNode* cur = *pphead;
		while (cur->next)
		{
			cur = cur->next;
		}
		//2.链在一起
		cur->next = newnode;
		newnode->next = NULL;
	}
}

//2.头插
void SLTPushFront(SLTNode** pphead, SLDataType x)
{
	assert(pphead);

	SLTNode* newnode = SLTBuyNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
}

//4.尾删
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);
	if ((*pphead)->next == NULL)
	{
		//只有一个节点
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//1.找倒数第二个节点
		SLTNode* cur = *pphead;
		while (cur->next->next)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

//5.头删
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);
	if ((*pphead)->next == NULL)
	{
		//只有一个节点
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//先存储头节点的下一个节点
		SLTNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}
}

//6、查找
SLTNode* SLTFind(SLTNode* phead, SLDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x) return cur;
		cur = cur->next;
	}	
	return NULL;
}

//7.在指定位置之前插入
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLDataType x)
{
	assert(pphead);
	assert(pos->next);

	SLTNode* newnode = SLTBuyNode(x);
	if (*pphead == pos)
	{
		//头插
		SLTPushFront(pphead, x);
	}
	else
	{
		//找到pos的前一个节点
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		newnode->next = pos;
		prev->next = newnode;
	}
}

//8.删除pos节点
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && *pphead);
	assert(pos);

	if (pos == *pphead)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//找到pos的前一个节点
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		free(pos);
		pos = NULL;
		prev->next = NULL;
	}	
}

//9.在指定位置之后插入
void SLTInsertAfter(SLTNode* pos, SLDataType x)
{
	assert(pos);

	SLTNode* newnode = SLTBuyNode(x);
	SLTNode* next = pos->next;
	//进行插入
	newnode->next = next;
	pos->next = newnode;
}

//10.删除pos之后的节点
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos && pos->next);
	SLTNode* del = pos->next;
	SLTNode* next = del->next;
	free(del);
	del = NULL;
	pos->next = next;
}

//11.销毁链表
void SLTDestroy(SLTNode** pphead)
{
	SLTNode* cur = *pphead;

	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}