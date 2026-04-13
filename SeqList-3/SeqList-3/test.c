#include "SeqList.h"

//void test1()
//{
//	SL sl;
//	SLInit(&sl);
//	
//	//SLPushBack(&sl, 1);
//	//SLPushBack(&sl, 2);
//	//SLPushBack(&sl, 3);
//	//SLPushBack(&sl, 4);
//
//	//SLPrint(&sl);
//
//	SLPushFront(&sl, 1);
//	SLPushFront(&sl, 2);
//	SLPushFront(&sl, 3);
//	SLPushFront(&sl, 4);
//	SLPrint(&sl);
//
//	//SLPopBack(&sl);
//	//SLPrint(&sl);
//
//	//SLPopBack(&sl);
//	//SLPrint(&sl);
//
//	//SLPopBack(&sl);
//	//SLPrint(&sl);
//
//	//SLPopBack(&sl);
//	//SLPrint(&sl);
//
//	//SLPopBack(&sl);
//	//SLPrint(&sl);
//
//	//SLPopFront(&sl);
//	//SLPrint(&sl);
//
//	//SLPopFront(&sl);
//	//SLPrint(&sl);
//
//	//SLPopFront(&sl);
//	//SLPrint(&sl);
//
//	//SLPopFront(&sl);
//	//SLPrint(&sl);
//
//	//SLPopFront(&sl);
//	//SLPrint(&sl);
//
//
//}

//void test2()
//{
//	SL sl;
//	SLInit(&sl);
//
//	SLPushFront(&sl, 1);
//	SLPushFront(&sl, 2);
//	SLPushFront(&sl, 3);
//	SLPushFront(&sl, 4);
//	SLPrint(&sl);
//
//	int find = SLFind(&sl, 1);
//	if (find == -1) printf("没找到！\n");
//	else printf("找到了\n");
//
//
//	//SLInsert(&sl, 1, 99);
//	//SLPrint(&sl);
//
//	//SLInsert(&sl, 4, 99);
//	//SLPrint(&sl);
//
//
//	//SLErase(&sl, 1);
//	//SLPrint(&sl);
//
//	//SLErase(&sl, 1);
//	//SLPrint(&sl);
//
//	//SLErase(&sl, 1);
//	//SLPrint(&sl);
//
//	//SLErase(&sl, 1);
//	//SLPrint(&sl);
//
//}

//int main()
//{
//	//test1();
//	//test2();
//  //test3();
//	return 0;
//}

//void test3()
//{
//	Contact con;
//	ContactInit(&con);
//
//	ContactAdd(&con);
//	ContactShow(&con);
//
//	//ContactErase(&con);
//	//ContactShow(&con);
//
//	ContactModify(&con);
//	ContactShow(&con);
//
//}


void menu()
{
	printf("****************通讯录***************\n");
	printf("*****1.添加联系人 2.删除联系人*******\n");
	printf("*****3.查找联系人 4.修改联系人*******\n");
	printf("*****5.展示联系人 0.退出通讯录*******\n");
	printf("*************************************\n");
}

int main()
{
	int op = -1;
	Contact* con;
	ContactShow(&con);

	do
	{
		menu();
		printf("请选择您的操作:\n");
		scanf("%d", &op);

		switch (op)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 0:
			break;
		default:
			printf("输入错误,请重新输入!\n");
			break;
		}

	} while (op);

	ContactDestroy(&con);
	return 0;
}