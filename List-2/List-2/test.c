#include "List.h"

void test()
{
	LTNode* plist = NULL;
	LTInit(&plist);

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

	LTPushFront(plist, 1);
	LTPushFront(plist, 2);
	LTPushFront(plist, 3);
	LTPushFront(plist, 4);
	LTPrint(plist);

	LTDestroy(plist);
	//显式将哨兵位置为空
	plist = NULL;
	LTPrint(plist);


	//LTNode* find = LTFind(plist, 1);
    //LTInsert(find, 99);
    //LTPrint(plist);

	//LTErase(find);
	//LTPrint(plist);


	//LTNode* find1 = LTFind(plist, 1);
	//LTInsert(find1, 99);
	//LTPrint(plist);

	//LTNode* find2 = LTFind(plist, 2);
	//LTInsert(find2, 77);
	//LTPrint(plist);

	//LTNode* find4 = LTFind(plist, 4);
	//LTInsert(find4, 88);
	//LTPrint(plist);
	//if (find == NULL)
	//{
	//	printf("没找到！\n");
	//	exit(-1);
	//}
	//printf("找到了！\n");

	//LTPopFront(plist);
	//LTPrint(plist);
	//
	//LTPopFront(plist);
	//LTPrint(plist);

	//LTPopFront(plist);
	//LTPrint(plist);

	//LTPopFront(plist);
	//LTPrint(plist);

	//LTPopFront(plist);
	//LTPrint(plist);

}


int main()
{
	test();
	return 0;
}