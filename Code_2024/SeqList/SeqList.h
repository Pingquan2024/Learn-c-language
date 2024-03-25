#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//��̬˳���
//typedef int SLDataType;
//#define N 100
//struct SeqList
//{
//	SLDataType a[N];
//	int size;
//};

//��̬˳���
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;   //ָ��̬���ٵ�����
	int size;            //�洢����Ч���ݵĸ���
	int capacity;        //����
}SL;

//��ʼ��
void SLInit(SL* ps1);

//����
void SLDestroy(SL* ps1);

//��ӡ
void SLPrint(SL* ps1);

//ͷ��
void SLPushFront(SL* ps1, SLDataType x);

//β��
void SLPushBack(SL* ps1, SLDataType x);

//ͷɾ
void SLPopFront(SL* ps1);

//βɾ
void SLPopBack(SL* ps1);

//posλ�ò���
void SLInsert(SL* ps1, int pos, SLDataType x);

//posλ��ɾ��
void SLErase(SL* ps1, int pos);

//����
int SLFind(SL* ps1, SLDataType x);
/*�ҵ������±꣬�Ҳ�������-1*/

//�޸�
void SLModify(SL* ps1, int pos, SLDataType x);