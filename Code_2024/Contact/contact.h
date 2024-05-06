#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

#define DEFAULT_SIZE 3
#define INC_SZ 2

enum OPTIONS
{
	EXIT,                //0
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

typedef struct PeoInfo     //PeoInfo为结构体名称
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;                  //PeoInfo为typedef的名字

////静态版本
//typedef struct Contact   //Contact为结构体名称
//{
//	PeoInfo data[MAX];
//	int size;
//}Contact;

//动态的版本
typedef struct Contact
{
	PeoInfo* data;          //指向存储数据的空间
	int size;               //记录当前放的有效元素个数
	int capacity;           //通讯录当前的最大容量
}Contact;

         /*函数声明*/

//初始化通讯录
void InitContact(Contact* pc);

//增加联系人
void AddContact(Contact* pc);

//删除联系人
void DelContact(Contact* pc);

//查找联系人
void SearchContact(Contact* pc);

//修改联系人
void ModifyContact(Contact* pc);

//显示联系人
void ShowContact(Contact* pc);

//按名字排序
void SortContact(Contact* pc);

//销毁通讯录
void DestroyContact(Contact* pc);

//保存通讯录信息到文件
void SaveContact(Contact* pc);