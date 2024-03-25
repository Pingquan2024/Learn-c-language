#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//静态顺序表
//typedef int SLDataType;
//#define N 100
//struct SeqList
//{
//	SLDataType a[N];
//	int size;
//};

//动态顺序表
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;   //指向动态开辟的数组
	int size;            //存储的有效数据的个数
	int capacity;        //容量
}SL;

//初始化
void SLInit(SL* ps1);

//销毁
void SLDestroy(SL* ps1);

//打印
void SLPrint(SL* ps1);

//头插
void SLPushFront(SL* ps1, SLDataType x);

//尾插
void SLPushBack(SL* ps1, SLDataType x);

//头删
void SLPopFront(SL* ps1);

//尾删
void SLPopBack(SL* ps1);

//pos位置插入
void SLInsert(SL* ps1, int pos, SLDataType x);

//pos位置删除
void SLErase(SL* ps1, int pos);

//查找
int SLFind(SL* ps1, SLDataType x);
/*找到返回下标，找不到返回-1*/

//修改
void SLModify(SL* ps1, int pos, SLDataType x);