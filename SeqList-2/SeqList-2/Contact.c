#include "Contact.h"
#include "SeqList.h"

//通讯录的创建
void ContactInit(Contact* con)
{
	SLInit(con);
}
//添加通讯录数据
void ContactAdd(Contact* con)
{
	PeoInfo info;

	printf("-------开 始 添 加------\n");
	//获取用户的输入
	printf("请输入要添加的联系人姓名：\n");
	scanf("%s", info.name);

	printf("请输入要添加的联系人性别：\n");
	scanf("%s", info.gender);

	printf("请输入要添加的联系人年龄：\n");
	scanf("%d", &info.age);

	printf("请输入要添加的联系人电话：\n");
	scanf("%s", info.tel);

	printf("请输入要添加的联系人住址：\n");
	scanf("%s", info.addr);

	printf("-------添 加 结 束------\n");

	printf("\n");
	//添加联系人数据
	SLPushBack(con, info);

}
//以name为标准进行查找
int FindByName(Contact* con,char name[])
{
	for (int i = 0; i < con->size; i++)
	{
		if (0 == strcmp(con->arr[i].name,name)) return i;
	}
	return -1;
}
//删除通讯录数据
void ContactDel(Contact* con)
{
	//以name为标准进行查找
	char name[NAME_MAX];
	printf("请输入要删除的联系人姓名：\n");
	scanf("%s", name);
	int find = FindByName(con,name);
	if (find < 0)
	{
		printf("要删除的联系人数据不存在!\n");
		return;
	}

	SLErase(con, find);
	printf("删除成功!\n");
}
//展示通讯录数据
void ContactShow(Contact* con)
{
	//打印表头
	printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "住址");
	for (int i = 0; i < con->size; i++)
	{
		printf("%3s %3s %3d %3s %3s\n"
			, con->arr[i].name
			, con->arr[i].gender
			, con->arr[i].age
			, con->arr[i].tel
			, con->arr[i].addr);
	}
	printf("\n");
}
//修改通讯录数据
void ContactModify(Contact* con)
{
	//以name为标准进行查找 
	char name[NAME_MAX];
	printf("请输入要修改的联系人姓名：\n");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("要修改的联系人数据不存在!\n");
		return;
	}
	
	printf("请输入新的联系人姓名：\n");
	scanf("%s", con->arr[find].name);

	printf("请输入新的联系人性别：\n");
	scanf("%s", con->arr[find].gender);

	printf("请输入新的联系人年龄：\n");
	scanf("%d", &con->arr[find].age);

	printf("请输入新的联系人电话：\n");
	scanf("%s", con->arr[find].tel);

	printf("请输入新的联系人住址：\n");
	scanf("%s", con->arr[find].addr);

	printf("修改成功!\n");
}
//查找通讯录数据
void ContactFind(Contact* con)
{
	//以name为标准进行查找 
	char name[NAME_MAX];
	printf("请输入要查找的联系人姓名：\n");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("要查找的联系人数据不存在!\n");
		return;
	}
	//打印表头
	printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "住址");
	//打印查找的联系人数据
	printf("%3s %3s %3d %3s %3s\n"
		, con->arr[find].name
		, con->arr[find].gender
		, con->arr[find].age
		, con->arr[find].tel
		, con->arr[find].addr);
}
//销毁通讯录数据
void ContactDestroy(Contact* con)
{
	SLDestroy(con);
}
