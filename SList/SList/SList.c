#include "SList.h"

//打印
void SLTPrint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}
//申请空间
SLTNode* SLTBuyNode(SLDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc failed!\n");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}
//尾插
void SLTPushBack(SLTNode** pphead, SLDataType x)
{
	//修改指针内部成员-一级指针
	//修改指针本身-二级指针
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	//判断是否为空链表
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找到尾节点
		SLTNode* ptail = *pphead;
	    //为避免头结点的修改，因此用ptail代替pphead
		while (ptail->next)
		{
			ptail = ptail->next;
		}
		//ptail指向的就是尾节点
		ptail->next = newnode;
	}
}
//头插
void SLTPushFront(SLTNode** pphead, SLDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);

	newnode->next = *pphead;
	*pphead = newnode;
}
//尾删
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);//链表不能为空
	//链表只有一个节点
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//多个节点
	else
	{
		SLTNode* ptail = *pphead;
		SLTNode* prev = *pphead;
		while (ptail->next)
		{
			//prev保存ptail的前驱
			prev = ptail;
			ptail = ptail->next;
		}
		free(ptail);
		ptail = NULL;
		prev->next = NULL;
	}
	
}
//头删
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);//链表不能为空
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}
//查找
SLTNode* SLTFind(SLTNode* phead, SLDataType x)
{
	assert(phead);
	SLTNode* pcur = phead;
	while (pcur)
	{
		if (pcur->data == x) return pcur;
		pcur = pcur->next;
	}
	//pcur会走到最后一个节点的后面
	return NULL;
}
//在指定位置之前插入数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLDataType x)
{
	//在第一个节点前插入元素，头节点会发生改变，因此需要传入pphead
	assert(pphead && *pphead);
	assert(pos);
	//若*pphead == pos 即为头插，调用头插函数即可
	if (*pphead == pos)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode* newnode = SLTBuyNode(x);
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		//prev就是pos节点的前一个节点
		//1.先让newnode指向pos
		newnode->next = pos;
		//2.再让prev指向newnode
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
	assert(pphead && *pphead);//防止传入空指针 空链表 
	assert(pos);//空节点
	//如果*pphead == pos 即为头删
	if (*pphead == pos)
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
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
//删除pos之后的节点
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos && pos->next);
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
	SLTNode* next = *pphead;
	while (pcur)
	{
		next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}