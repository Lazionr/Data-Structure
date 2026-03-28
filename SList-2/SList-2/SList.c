#include "SList.h"

void SLTprint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

SLTNode* SLTBuyNode(SLDataType x)
{
	SLTNode* p = (SLTNode*)malloc(sizeof(SLTNode));
	if (p == NULL)
	{
		perror("malloc failed!\n");
		exit(-1);
	}
	p->data = x;
	p->next = NULL;
	return p;
}

void SLTPushBack(SLTNode** pphead, SLDataType x)
{
	//*pphead为空表示为空链表

	//直接传入NULL时加上断言,不能对空指针直接解引用
	assert(pphead);
	
	SLTNode* newnode = SLTBuyNode(x); 

	//空链表需要修改头指针本身，使用二级指针
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* ptail = *pphead;
		//找到到最后一个节点
		while (ptail->next)
		{
			ptail = ptail->next;
		}
		ptail->next = newnode;
	}
}

void SLTPushFront(SLTNode** pphead, SLDataType x)
{
	assert(pphead);

	SLTNode* newnode = SLTBuyNode(x);

	newnode->next = *pphead;
	*pphead = newnode;
}

void SLTPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);
	
	if ((*pphead)->next == NULL)
	{
		//->的优先级高于* 
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* ptail = *pphead;
		SLTNode* prev = *pphead;
		while (ptail->next)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		//此时prev就是倒数第二个节点的指针
		free(ptail);
		ptail = NULL;
		prev->next = NULL;
	}
}

void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);

	//SLTNode* prev = *pphead;
	//*pphead = prev->next;
	//free(prev);
	//prev = NULL;

	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

SLTNode* SLTFind(SLTNode* phead, SLDataType x)
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		if (pcur->data == x) return pcur;
		pcur = pcur->next;
	}
	//pcur == NULL
	return NULL;
}

//在指定位置之前插入数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLDataType x)
{
	assert(pphead && *pphead);
	assert(pos);

	SLTNode* newnode = SLTBuyNode(x);

	if (*pphead == pos)
	{
		//头插
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		newnode->next = pos;
		prev->next = newnode;
	}

}

//在指定位置之后插入数据
void SLTInsertAfter(SLTNode* pos, SLDataType x)
{
	assert(pos);

	SLTNode* newnode = SLTBuyNode(x);

	newnode->next = pos->next;
	pos->next = newnode;
}

//删除pos节点
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && *pphead);
	assert(pos);

	if (pos == *pphead)
	{
		//头删
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
//删除pos之后的节点
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos && pos->next);

	//pos->next = pos->next->next;
	//此时pos->next指向的已经是pos->next->next的指针了，释放错误
	//free(pos->next);
	//pos->next = NULL;

	SLTNode* del = pos->next;

	pos->next = pos->next->next;
	free(del);
	del = NULL;
}

//销毁链表
void SListDestroy(SLTNode** pphead)
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