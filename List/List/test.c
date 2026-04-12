#include "List.h"

void test1()
{
	LTNode* plist = LTInit();


	LTPushFront(plist, 1);
	LTPushFront(plist, 2);
	LTPushFront(plist, 3);
	LTPushFront(plist, 4);

	LTPrint(plist);

	//LTPushBack(plist, 1);
	//LTPushBack(plist, 2);
	//LTPushBack(plist, 3);
	//LTPushBack(plist, 4);

	//LTPrint(plist);

	//LTPopBack(plist);
	//LTPrint(plist);

	//LTPopBack(plist);
	//LTPrint(plist);

	//LTPopBack(plist);
	//LTPrint(plist);

	//LTPopBack(plist);
	//LTPrint(plist);

	//LTPopFront(plist);
	//LTPrint(plist);

	//LTPopFront(plist);
	//LTPrint(plist);

	//LTPopFront(plist);
	//LTPrint(plist);

	//LTPopFront(plist);
	//LTPrint(plist);

	//LTNode* find = LTFind(plist, 4);
	//if (find == NULL) printf("没找到！\n");
	//else printf("找到了！\n");

	//LTInsert(find, 99);
	//LTPrint(plist);

	//LTInsert(find, 88);
	//LTPrint(plist);

	//LTInsert(find, 77);
	//LTPrint(plist);

	//LTNode* pos = LTFind(plist, 99);

	//LTErase(pos);
	//LTPrint(plist);

	LTDestroy(plist);
	plist = NULL;
	LTPrint(plist);
}


int main()
{
	test1();
	return 0;
}
