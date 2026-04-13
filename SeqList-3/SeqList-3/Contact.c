#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"

//初始化通讯录
void ContactInit(Contact* con)
{
	SLInit(con);
}
//添加通讯录数据
void ContactAdd(Contact* con)
{
	PeoInfo info;

	//创建联系人数据
	printf("-------开 始 添 加------\n");

	printf("请输入要添加的联系人姓名:\n");
	scanf("%s", info.name);

	printf("请输入要添加的联系人性别:\n");
	scanf("%s", info.gender);

	printf("请输入要添加的联系人年龄:\n");
	scanf("%d", &info.age);

	printf("请输入要添加的联系人住址:\n");
	scanf("%s", info.addr);

	printf("请输入要添加的联系人电话:\n");
	scanf("%s", info.tel);

	printf("-------添 加 结 束------\n");

	printf("\n");

	//调用任意一个插入函数
	SLPushBack(con, info);

}

//以名字为标准进行查找
int FindByName(Contact* con,char name[])
{
	for (int i = 0; i < con->size; i++)
	{
		if (0 == strcmp(con->arr[i].name, name)) return i;
	}
	return -1;
}

//删除联系人数据
void ContactErase(Contact* con)
{
	//以名字为标准进行查找
	char name[NAME_MAX];
	printf("请输入要删除的联系人姓名:\n");
	scanf("%s", name);

	int find = FindByName(con,name);
	if (find < 0)
	{
		printf("要删除的联系人不存在!\n");
		return;
	}

	SLPopBack(con);
	printf("删除成功!\n");
}

//展示联系人数据
void ContactShow(Contact* con)
{
	if (con->size == 0)
	{
		printf("无联系人数据!\n");
		return;
	}
	//打印表头
	printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "住址");

	for (int i = 0; i < con->size; i++)
	{
		printf("%3s %3s %3d %3s %3s\n"
			, con->arr[i].name
			, con->arr[i].gender
			, con->arr[i].age
			, con->arr[i].addr
			, con->arr[i].tel);
	}
	printf("\n");

}

//修改联系人数据
void ContactModify(Contact* con)
{
	//以名字为标准进行查找
	char name[NAME_MAX];
	printf("请输入要修改的联系人姓名:\n");
	scanf("%s", name);

	int find = FindByName(con,name);
	if (find < 0)
	{
		printf("要修改的联系人数据不存在!\n");
		return;
	}

	//进行修改
	printf("请输入修改后的联系人姓名:\n");
	scanf("%s", con->arr[find].name);

	printf("请输入修改后的联系人性别:\n");
	scanf("%s", con->arr[find].gender);

	printf("请输入修改后的联系人年龄:\n");
	scanf("%d", &con->arr[find].age);

	printf("请输入修改后的联系人地址:\n");
	scanf("%s", con->arr[find].addr);

	printf("请输入修改后的联系人电话:\n");
	scanf("%s", con->arr[find].tel);

	printf("修改成功!\n");

}


