#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

//void test1()
//{
//	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
//	node1->data = 1; 
//	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
//	node2->data = 2;
//	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
//	node3->data = 3;
//	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));
//	node4->data = 4;
//
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;
//	node4->next = NULL;
//
//	SLTNode* plist = node1;
//	SLTprint(plist);
//}

void test2()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTprint(plist);

	SListDestroy(&plist);
	SLTprint(plist);
	//SLTNode* find = SLTFind(plist, 1);

	//SLTInsert(&plist, find, 99);
	//SLTprint(plist);
	
	//SLTErase(&plist, find);
	//SLTprint(plist);

	//SLTEraseAfter(find);
	//SLTprint(plist);

	//SLTInsertAfter(find, 11);
	//SLTprint(plist);
	//if (find == NULL)
	//{
	//	printf("没有找到！\n");
	//}
	//else
	//{
	//	printf("找到了！\n");
	//}


	//SLTPushFront(&plist, 6);
	//SLTPushFront(&plist, 7);
	//SLTPushFront(&plist, 8);
	//SLTPushFront(&plist, 9);
	//SLTprint(plist);

	//SLTPopBack(&plist);
	//SLTprint(plist);

	//SLTPopBack(&plist);
	//SLTprint(plist);

	//SLTPopBack(&plist);
	//SLTprint(plist);

	//SLTPopBack(&plist);
	//SLTprint(plist);

	//SLTPopBack(&plist);
	//SLTprint(plist);

	//SLTPopBack(&plist);
	//SLTprint(plist);

	//SLTPopBack(&plist);
	//SLTprint(plist);

	//SLTPopBack(&plist);
	//SLTprint(plist);

	//SLTPopFront(&plist);
	//SLTprint(plist);

	//SLTPopFront(&plist);
	//SLTprint(plist);

	//SLTPopFront(&plist);
	//SLTprint(plist);

	//SLTPopFront(&plist);
	//SLTprint(plist);

	//SLTPopFront(&plist);
	//SLTprint(plist);

	
}


int main()
{
	//test1();
	test2();
	return 0;
}