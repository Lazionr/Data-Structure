#pragma once
#define NAME_MAX 20
#define GENDER_MAX 15
#define TEL_MAX 20
#define ADDR_MAX 20

typedef struct PersonInfo
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}PeoInfo;

//前置声明
typedef struct SeqList Contact;

//初始化通讯录
void ContactInit(Contact* con);
//添加通讯录数据
void ContactAdd(Contact* con);
//删除通讯录数据
void ContactDel(Contact* con);
//修改通讯录数据
void ContactModify(Contact* con);
//查找通讯录数据
void ContactFind(Contact* con);
//展示通讯录数据
void ContactShow(Contact* con);
//销毁通讯录数据
void ContactDestroy(Contact* con);