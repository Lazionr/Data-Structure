#pragma once
#define NAME_MAX 100
#define GENDER_MAX 5
#define TEL_MAX 11
#define ADDR_MAX 100

//定义联系人数据结构
//姓名 性别 年龄 电话 地址
typedef struct PersonInfo
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char addr[ADDR_MAX];
	char tel[TEL_MAX];
}PeoInfo;

//前置声明
typedef struct SeqList Contact;

//初始化通讯录
void ContactInit(Contact* con);

//添加通讯录数据
void ContactAdd(Contact* con);

//展示联系人数据
void ContactShow(Contact* con);

//删除联系人数据
void ContactErase(Contact* con);

//修改联系人数据
void ContactModify(Contact* con);

//查找通讯录数据
void ContactFind(Contact* con);

//销毁通讯录
void ContactDestroy(Contact* con);





