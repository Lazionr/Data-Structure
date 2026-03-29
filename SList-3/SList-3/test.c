#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

//void test1()
//{
//	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
//	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
//	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
//	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));
//
//	node1->data = 1; node2->data = 2;
//	node3->data = 3; node4->data = 4;
//
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;
//	node4->next = NULL;
//
//	SLTNode* plist = node1;
//	SLTPrint(plist);
//}

void test2()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);

	SLTPrint(plist);

	//SLTNode* find = SLTFind(plist, 1);

	SLTDestroy(&plist);
	SLTPrint(plist);
	//SLTEraseAfter(find);
	//SLTPrint(plist);
    //SLTEraseAfter(find, 99);
	//SLTPrint(plist);

	//SLTErase(&plist, find);
	//SLTPrint(plist);

	//SLTInsert(&plist, find, 99);
	//SLTPrint(plist);
	//if (find == NULL) printf("没找到！\n");
	//else printf("找到了！\n");

	//SLTPopFront(&plist);
	//SLTPrint(plist);

	//SLTPopFront(&plist);
	//SLTPrint(plist);

	//SLTPopFront(&plist);
	//SLTPrint(plist);

	//SLTPopFront(&plist);
	//SLTPrint(plist);

	//SLTPopFront(&plist);
	//SLTPrint(plist);

	//SLTPushFront(&plist, 1);
	//SLTPushFront(&plist, 2);
	//SLTPushFront(&plist, 3);
	//SLTPushFront(&plist, 4);

	//SLTPrint(plist);

	//SLTPopBack(&plist);
	//SLTPrint(plist);

	//SLTPopBack(&plist);
	//SLTPrint(plist);

	//SLTPopBack(&plist);
	//SLTPrint(plist);

	//SLTPopBack(&plist);
	//SLTPrint(plist);

	//SLTPopBack(&plist);
	//SLTPrint(plist);
}

int main()
{
	//test1();

	test2();
	return 0;
}