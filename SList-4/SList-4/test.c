#include "SList.h"

void test1()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);

	SLTPrint(plist);

	//SLTPushFront(&plist, 1);
	//SLTPushFront(&plist, 2);
	//SLTPushFront(&plist, 3);
	//SLTPushFront(&plist, 4);

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

	//SLTNode* find = SLTFind(plist, 5);
	//if (find == NULL) printf("Not Found!\n");
	//else printf("Found!\n");

	//SLTNode* find = SLTFind(plist, 1);
	//SLTInsert(&plist, find, 99);
	//SLTPrint(plist);

	//SLTErase(&plist, find);
	//SLTPrint(plist);

	//SLTNode* find = SLTFind(plist, 4);
	//SLTInsertAfter(find, 99);
	//SLTPrint(plist);

	//SLTNode* find = SLTFind(plist, 3);
	//SLTEraseAfter(find);
	//SLTPrint(plist);

	SLTDestroy(&plist);
	SLTPrint(plist);
}


int main()
{
	test1();
	return 0;
}