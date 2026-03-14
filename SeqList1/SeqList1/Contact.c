#include "Contact.h"
#include "SeqList.h"

//通讯录的初始化
void ContactInit(Contact* con)
{
	SLInit(con);
}
//通讯录的销毁
void ContactDestroy(Contact* con)
{
	SLDestroy(con);
}
//通讯录添加数据
void ContactAdd(Contact* con)
{
	PeoInfo info;

	printf("-----开始添加-----\n");

	printf("请输入联系人姓名：\n");
	scanf("%s", info.name);

	printf("请输入联系人性别：\n");
	scanf("%s", info.gender);

    printf("请输入联系人年龄：\n");
	scanf("%d", &info.age);

	printf("请输入联系人电话：\n");
	scanf("%s", info.tel);

	printf("请输入联系人住址：\n");
	scanf("%s", info.addr);

	printf("-----添加完成-----\n");
	printf("\n");

	SLPushBack(con, info);
}
//判断联系人数据是否存在
int FindByName(Contact* con, char name[])
{
	for (int i = 0; i < con->size; i++)
	{
		if (0 == strcmp(name, con->arr->name))
		{
			//找到了
			return i;
		}
	}
	return -1;
}
//通讯录删除数据
void ContactDel(Contact* con)
{
	char name[NAME_MAX];
	printf("请输入要删除的联系人的姓名：\n");
	scanf("%s", name);
	 //根据姓名来判断联系人数据是否存在 
	int find = FindByName(con, name);
	if (find < 0)
	{
		//不存在
		printf("联系人数据不存在，删除失败！");
		return;
	}
	SLErase(con,find);
	printf("删除成功！\n");
}
//展示通讯录数据
void ContactShow(Contact* con)
{
	//打印表头：姓名 性别 年龄 电话 地址
	printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "地址");
	for (int i = 0; i < con->size; i++)
	{
		printf("%s %s %d %s %s\n",
			con->arr[i].name, 
			con->arr[i].gender,
			con->arr[i].age,
			con->arr[i].tel,
			con->arr[i].addr);
	}
	printf("\n");
}
//通讯录的修改
void ContactModify(Contact* con)
{
	char name[NAME_MAX];
	//判断要修改的联系人数据是否存在
	printf("请输入要修改的联系人姓名：\n");
	scanf("%s", name);
	int find = FindByName(con, name);

	if (find < 0)
	{
		//不存在
		printf("当前联系人不存在!\n");
		return;
	}
	//此时进行修改
	printf("请输入新的联系人姓名：\n");
	scanf("%s", con->arr[find].name);

	printf("请输入新的联系人性别：\n");
	scanf("%s", con->arr[find].gender);

	printf("请输入新的联系人年龄：\n");
	scanf("%d", &con->arr[find].age);

	printf("请输入新的联系人电话：\n");
	scanf("%s", con->arr[find].tel);

	printf("请输入新的联系人姓名：\n");
	scanf("%s", con->arr[find].addr);

	printf("修改成功！\n");
}
//通讯录的查找
void ContactFind(Contact* con)
{
	char name[NAME_MAX];
	//判断是否存在
	printf("请输入要查找的联系人姓名：\n");
	scanf("%s", name);

	int find = FindByName(con, name);

	if (find < 0)
	{
		printf("当前联系人不存在！\n");
		return;
	}
	//打印表头：姓名 性别 年龄 电话 地址
	printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "地址");
	printf("%s %s %d %s %s\n",
		con->arr[find].name,
		con->arr[find].gender,
		con->arr[find].age,
		con->arr[find].tel,
		con->arr[find].addr);
}