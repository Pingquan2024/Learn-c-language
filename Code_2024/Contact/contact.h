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

enum OPTIONS
{
	EXIT,               //0
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

typedef struct PeoInfo   //PeoInfoΪ�ṹ������
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;               //PeoInfoΪtypedef������

//��̬�汾
typedef struct Contact   //ContactΪ�ṹ������
{
	PeoInfo data[MAX];
	int size;
}Contact;

//��������

//��ʼ��ͨѶ¼
void InitContact(Contact* pc);

//������ϵ��
void AddContact(Contact* pc);

//ɾ����ϵ��
void DelContact(Contact* pc);

//������ϵ��
void SearchContact(Contact* pc);

//�޸���ϵ��
void ModifyContact(Contact* pc);

//��ʾ��ϵ��
void ShowContact(Contact* pc);

//����������
void SortContact(Contact* pc);