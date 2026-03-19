#include "SeqList.h"
#include "Contact.h"
//void test1()
//{
//	SL sl;
//	SLInit(&sl);
//
//	SLPushBack(&sl,11);
//	SLPushBack(&sl,22);
//	SLPushBack(&sl,33);
//	//SLPrint(&sl);
//	//11 22 33
//
//	SLPushFront(&sl, 99);
//	SLPushFront(&sl, 88);
//	SLPushFront(&sl, 77);
//	//SLPrint(&sl);
//	//77 88 99
//
//	//77 88 99 11 22 33
//
//	SLPopBack(&sl);
//	SLPopFront(&sl);
//	SLPopFront(&sl);
//	//SLPrint(&sl);
//	//99 11 22
//
//	SLInsert(&sl, 1, 66);//99 66 11 22
//	SLInsert(&sl, 4, 55);//99 66 11 22 55;
//	//SLPrint(&sl);
//
//	SLErase(&sl, 4);//99 66 11 22
//	SLErase(&sl, 0);//66 11 22
//	SLErase(&sl, 1);//66 22
//	SLPrint(&sl);
//}

//void test2()
//{
//	Contact con;
//	ContactInit(&con);
//
//	ContactAdd(&con);
//	ContactAdd(&con);
//	ContactShow(&con);
//
//	ContactModify(&con);
//	ContactShow(&con);
//
//	ContactFind(&con);
//	ContactShow(&con);
//
//	ContactDestroy(&con);
//}

//int main()
//{
//	//test1();
//	//test2();
//	return 0;
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
	Contact con;
	ContactInit(&con);
	do{
		menu();
		printf("请选择您的操作：\n");
		scanf("%d", &op);

		switch(op) 
		{
		case 1:
			ContactAdd(&con);
			break;
		case 2:
			ContactDel(&con);
			break;
		case 3:
			ContactFind(&con);
			break;
		case 4:
			ContactModify(&con);
			break;
		case 5:
			ContactShow(&con);
			break;
		case 0:
			printf("退出通讯录!\n");
			break;
		default:
			printf("输入错误,请重新输入!\n");
			break;
		}
	} while (op);

	ContactDestroy(&con);
	return 0;
}