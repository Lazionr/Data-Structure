#include "SList.h"


void test1()
{
	SLTNode* plist = NULL;

	SLTPushBack(&plist, 1);
    SLTPushBack(&plist, 2);
    SLTPushBack(&plist, 3);
    SLTPushBack(&plist, 4);

	SLTPrint(plist);

	SLTDestroy(&plist);
	SLTPrint(plist);

	//SLTNode* find = SLTFind(plist, 1);
	//SLTInsertAfter(find, 99);
	//SLTPrint(plist);


	//SLTEraseAfter(find);
	//SLTPrint(plist);














	//SLTNode* find4 = SLTFind(plist, 4);
	//SLTErase(&plist, find4);
	//SLTPrint(plist);

	//SLTNode* find3 = SLTFind(plist, 3);
	//SLTErase(&plist, find3);
	//SLTPrint(plist);

	//SLTNode* find2 = SLTFind(plist, 2);
	//SLTErase(&plist, find2);
	//SLTPrint(plist);

	//SLTNode* find1 = SLTFind(plist, 1);
	//SLTErase(&plist, find1);
	//SLTPrint(plist);

	//SLTInsert(&plist, find, 99);

	//SLTPushFront(&plist, 1);
	//SLTPushFront(&plist, 2);
	//SLTPushFront(&plist, 3);
	//SLTPushFront(&plist, 4);

	//SLTPrint(plist);

	//SLTNode* find = SLTFind(plist,9);
	//if (find == NULL)
	//{
	//	printf("未找到！\n");
	//	exit(1);
	//}
	//else
	//{
	//	printf("找到了！\n");
	//}


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
	test1();
	return 0;
}