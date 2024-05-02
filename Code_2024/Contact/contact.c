#include "contact.h"

//��ʼ��ͨѶ¼
void InitContact(Contact* pc)
{
	assert(pc);
	memset(pc->data, 0, sizeof(pc->data));
	pc->size = 0;
}

//������ϵ��
void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->size == MAX)
	{
		printf("ͨѶ¼�������޷����\n");
		return;
	}

	printf("����������>��");
	scanf("%s", pc->data[pc->size].name);
	printf("�������Ա�>��");
	scanf("%s", pc->data[pc->size].sex);	
	printf("����������>��");
	scanf("%d", &(pc->data[pc->size].age));
	printf("������绰>��");
	scanf("%s", pc->data[pc->size].tele);
	printf("�������ַ>��");
	scanf("%s", pc->data[pc->size].addr);

	pc->size++;
	printf("�ɹ�������ϵ��\n");
}

//ɾ����ϵ��
void DelContact(Contact* pc)
{
	assert(pc);

	if (pc->size == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
		return;
	}

	//��Ϊ�������ɾ��
	//1.�ҵ�Ҫɾ������
	char name[MAX_NAME] = { '\0'};
	printf("����Ҫɾ����ϵ�˵�����>��");
	scanf("%s", name);

	int del = 0;             //��¼Ҫɾ����λ��
	int flag = 0;            //��ʾҪɾ������ϵ���Ƿ����
	for (int i = 0; i < pc->size; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			del = i;
			flag = 1;
			break;
		}
	}

	if (flag == 0)
	{
		printf("Ҫɾ������ϵ�˲�����\n");
		return;
	}
	//ɾ������Ϊdel����ϵ��
	for (int i = del; i < pc->size; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->size--;

	printf("�ɹ�ɾ����ϵ��\n");
}

//������ϵ��
void SearchContact(Contact* pc)
{

}

//�޸���ϵ��
void ModifyContact(Contact* pc)
{

}

//��ʾ��ϵ��
void ShowContact(Contact* pc)
{
	assert(pc);

	printf("%-10s\t%-4s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (int i = 0; i < pc->size; i++)
	{
		printf("%-10s\t%-4d\t%-5s\t%-12s\t%-30s\n"
			,pc->data[i].name
			,pc->data[i].age 
			,pc->data[i].sex 
			,pc->data[i].tele
			,pc->data[i].addr
			);
	}
}

//����������
void SortContact(Contact* pc)
{

}