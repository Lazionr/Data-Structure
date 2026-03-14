#include "SeqList.h"

//void test01()
//{
//	SL sl;
//	SLInit(&sl);
//	PushBack(&sl, 1);
//	PushBack(&sl, 2);
//	PushBack(&sl, 3);
//	PushBack(&sl, 4);
//	//1 2 3 4
//	//PushBack(NULL, 1);
//	PushFront(&sl,3);
//	PushFront(&sl, 4);
//	PushFront(&sl, 5);
//	//5 4 3 1 2 3 4
//
//	PopFront(&sl);
//	//4 3 1 2 3 4
//
//	SLInsert(&sl, 0, 99);
//	SLInsert(&sl, 6, 99);
//	//99 4 3 1 2 3 4 99
//	SLErase(&sl, 0);
//	SLErase(&sl, 1);
//	//4 1 2 3 4 99
//	SLshow(sl);
//	SLDestroy(&sl);
//}

//void ContactTest()
//{
//	Contact con;
//	ContactInit(&con);
//	ContactAdd(&con);
//	ContactAdd(&con);
//	ContactShow(&con);
//
//	///ContactDel(&con);
//	//ContactShow(&con);
//
//	ContactModify(&con);
//	ContactFind(&con);
//	//ContactShow(&con);
//
//	ContactDestroy(&con);
//}

//int main()
//{
//	//test01();
//	ContactTest();
//	return 0;
//}

void menu()
{
	printf("*****************通讯录*****************\n");
	printf("*******1.增加联系人   2.删除联系人******\n");
	printf("*******3.修改联系人   4.查找联系人******\n");
	printf("*******5.展示联系人   0.退出通讯录******\n");
}

int main()
{
	Contact con;
	ContactInit(&con);
	int op = -1;
	do
	{
		printf("请选择您的操作：\n");
		menu();
		scanf_s("%d", &op);
		switch (op)
		{
		case 1:
			ContactAdd(&con);
			break;
		case 2:
			ContactDel(&con);
			break;
		case 3:
			ContactModify(&con);
			break;
		case 4:
			ContactFind(&con);
			break;
		case 5:
			ContactShow(&con);
			break;
		default:
			printf("请输入合理的操作！\n");
			break;
		}
	} while (op);

	ContactDestroy(&con);
}