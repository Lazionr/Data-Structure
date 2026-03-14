#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#define NAME_MAX 20
#define GENDER_MAX 10
#define TEL_MAX 20
#define ADDR_MAX 100
typedef struct PersonInfo
{
	//姓名，性别，年龄，号码，住址
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];

}PeoInfo;

//避免头文件的循环包含
//前置声明
typedef struct SeqList Contact;

//对通讯录的操作实际就是对顺序表的操作

//通讯录的初始化
void ContactInit(Contact* con);
//通讯录的销毁
void ContactDestroy(Contact* con);
//通讯录添加数据
void ContactAdd(Contact* con);
//通许录删除数据
void ContactDel(Contact* con);
//通讯录的修改
void ContactModify(Contact* con);
 //通讯录的查找
void ContactFind(Contact* con);
//展示通讯录数据
void ContactShow(Contact* con);