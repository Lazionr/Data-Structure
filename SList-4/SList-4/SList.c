#include "SList.h"

SLTNode* SLTBuyNode(SLTDataType x)
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));

	if (node == NULL)
	{
		perror("malloc failed!\n");
		exit(1);
	}
	node->data = x;
	node->next = NULL;

	return node;
}

//打印
void SLTPrint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL");
	printf("\n");
}

//尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);

	SLTNode* newnode = SLTBuyNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找到尾节点
		SLTNode* ptail = *pphead;
		while (ptail->next)
		{
			ptail = ptail->next;
		}
		ptail->next = newnode;
	}
}

//头插
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);

	SLTNode* newnode = SLTBuyNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//在头节点之前插入即可
		newnode->next = *pphead;
		//更新头节点
		*pphead = newnode;
	}
}

//尾删
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
		//找倒数第二个节点
		SLTNode* prev = *pphead;
		while (prev->next->next)
		{
			prev = prev->next;
		}
		SLTNode* ptail = prev->next;
		free(ptail);
		ptail = NULL;
		prev->next = NULL;
	}
}

//头删
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);

	SLTNode* plist = *pphead;
	SLTNode* next = plist->next;

	free(plist);
	plist = NULL;
	*pphead = next;
}


//查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	assert(phead);
	SLTNode* pcur = phead;
	while (pcur)
	{
		if (pcur->data == x) return pcur;
		pcur = pcur->next;
	}
	return NULL;
}

//在指定位置之前插入数据
void SLTInsert(SLTNode** pphead,SLTNode* pos, SLTDataType x)
{
	assert(pphead && *pphead);
	if (pos == *pphead)
	{	
		//头插
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode* newnode = SLTBuyNode(x);
		//找到pos之前的位置
		SLTNode* pcur = *pphead;

		while (pcur->next != pos)
		{
			pcur = pcur->next;
		}
		
		newnode->next = pos;
		pcur->next = newnode;
	}

}

//删除pos节点
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && *pphead);
	assert(pos);
	if (pos == *pphead)
	{
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		SLTNode* next = pos->next;
		prev->next = next;
		free(pos);
		pos = NULL;
	}
}

//在指定位置之后插入数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* next = pos->next;
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = next;
	pos->next = newnode;
}

//删除pos之后的节点
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos->next);
	SLTNode* del = pos->next;
	SLTNode* next = del->next;

	pos->next = next;
	free(del);
	del = NULL;
}

//销毁链表
void SLTDestroy(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* pcur = *pphead;
	while (pcur)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}