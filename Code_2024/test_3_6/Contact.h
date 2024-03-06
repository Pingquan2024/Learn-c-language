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

//���͵�����
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

//��̬�汾
//typedef struct Contact
//{
//	PeoInfo data[MAX];
//	int size;
//}Contact;

//��̬�汾
typedef struct Contact
{
	PeoInfo* data;  //ָ���˴�����ݵĿռ�
	int size;       //��¼��ǰ����ЧԪ�صĸ���
	int capacity;   //ͨѶ¼��ǰ���������
}Contact;


//��������

//��ʼ��
void InitContact(Contact* pc);

//������ϵ��
void AddContact(Contact* pc);

//��ʾ������ϵ�˵���Ϣ
void ShowContact(const Contact* pc);

//ɾ��ָ����ϵ��
void DelContact(Contact* pc);

//����ָ����ϵ��
void SearchContact(const Contact* pc);

//�޸�ָ����ϵ��
void ModifyContact(Contact* pc);

//����������
void SortContact(Contact* pc);

//����ͨѶ¼
void DestroyContact(Contact* pc);

//����ͨѶ¼��Ϣ���ļ�
void SaveContact(Contact* pc);