#include "SList.h"

//void test1()
//{
//	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
//	node1->data = 1;
//
//	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
//	node2->data = 2;
//
//	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
//	node3->data = 3;
//
//	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));
//	node4->data = 4;
//
//	//连接四个节点
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;
//	node4->next = NULL;
//
//	SLTNode* plist = node1;
//
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

	SListDestroy(&plist);
	SLTPrint(plist);


	//SLTPopBack(&plist);
	//SLTPrint(plist);

	//SLTPopBack(&plist);
	//SLTPrint(plist);

	//SLTPopBack(&plist);
	//SLTPrint(plist);

	//SLTPopBack(&plist);
	//SLTPrint(plist);


	//SLTPopFront(&plist);
	//SLTPrint(plist);

	//SLTPopFront(&plist);
	//SLTPrint(plist);

	//SLTPopFront(&plist);
	//SLTPrint(plist);

	//SLTPopFront(&plist);
	//SLTPrint(plist);

	//SLTNode* find = SLTFind(plist, 30);
	//if (find == NULL)
	//{
	//	printf("Not Found!\n");
	//}
	//else
	//{
	//	printf("Found!\n");
	//}
	//SLTNode* find = SLTFind(plist, 1);
	//SLTInsert(&plist, find, 99);
	//SLTInsertAfter(find, 99);
	//SLTErase(&plist, find);
	//SLTEraseAfter(find);
	//SLTPrint(plist);

}

int main()
{
	//test1();
	test2();
	return 0;
}