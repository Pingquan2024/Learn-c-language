#pragma once

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

#define DEFAULT_SZ 3
#define INC_SZ 2

enum OPTION
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

//类型的声明
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

//静态版本
//typedef struct Contact
//{
//	PeoInfo data[MAX];
//	int size;
//}Contact;

//动态版本
typedef struct Contact
{
	PeoInfo* data;  //指向了存放数据的空间
	int size;       //记录当前的有效元素的个数
	int capacity;   //通讯录当前的最大容量
}Contact;


//函数声明

//初始化
void InitContact(Contact* pc);

//增加联系人
void AddContact(Contact* pc);

//显示所有联系人的信息
void ShowContact(const Contact* pc);

//删除指定联系人
void DelContact(Contact* pc);

//查找指定联系人
void SearchContact(const Contact* pc);

//修改指定联系人
void ModifyContact(Contact* pc);

//按姓名排序
void SortContact(Contact* pc);

//销毁通讯录
void DestroyContact(Contact* pc);

//保存通讯录信息到文件
void SaveContact(Contact* pc);