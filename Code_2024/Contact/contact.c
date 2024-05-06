#include "contact.h"

int CheckCapacity(Contact* pc)
{
	if (pc->size == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			perror("ChechCapacity");
		}
		else
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			//printf("���ݳɹ�\n");
			return 1;
		}
	}
	return 1;
}

void LoadContact(Contact* pc)
{
	//���ļ�
	FILE* pf = fopen("contact.dat", "rb");

	if (pf == NULL)
	{
		//perror("LoadContact");
		return;
	}
	else
	{
		//���ļ�
		PeoInfo tmp = { 0 };
		while (fread(&tmp, sizeof(PeoInfo), 1, pf))
		{
			if (0 == CheckCapacity(pc))
			{
				return;
			}
			pc->data[pc->size] = tmp;
			pc->size++;
		}
	}

	fclose(pf);
	pf = NULL;
}

//��ʼ��ͨѶ¼
		/*��̬�汾*/
//void InitContact(Contact* pc)
//{
//	assert(pc);
//	memset(pc->data, 0, sizeof(pc->data));
//	pc->size = 0;
//}

void InitContact(Contact* pc)
{
	assert(pc);
	pc->data = (PeoInfo*)malloc(DEFAULT_SIZE * sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		perror("InitContact");
	}

	pc->size = 0;
	pc->capacity = DEFAULT_SIZE;

	//�����ļ��е���ϵ�˵�ͨѶ¼
	LoadContact(pc);
}


//������ϵ��
		/*��̬�汾*/
//void AddContact(Contact* pc)
//{
//	assert(pc);
//	if (pc->size == MAX)
//	{
//		printf("ͨѶ¼�������޷����\n");
//		return;
//	}
//
//	printf("����������>��");
//	scanf("%s", pc->data[pc->size].name);
//	printf("�������Ա�>��");
//	scanf("%s", pc->data[pc->size].sex);	
//	printf("����������>��");
//	scanf("%d", &(pc->data[pc->size].age));
//	printf("������绰>��");
//	scanf("%s", pc->data[pc->size].tele);
//	printf("�������ַ>��");
//	scanf("%s", pc->data[pc->size].addr);
//
//	pc->size++;
//	printf("�ɹ�������ϵ��\n");
//}

void AddContact(Contact* pc)
{
	assert(pc);
	if (0 == CheckCapacity(pc))
	{
		return;
	}

	printf("����������:>");
	scanf("%s", pc->data[pc->size].name);
	printf("����������:>");
	scanf("%d", &(pc->data[pc->size].age));
	printf("�������Ա�:>");
	scanf("%s", pc->data[pc->size].sex);
	printf("������绰:>");
	scanf("%s", pc->data[pc->size].tele);
	printf("�������ַ:>");
	scanf("%s", pc->data[pc->size].addr);

	pc->size++;
	printf("�ɹ�������ϵ��\n");

}

static int FindByName(const Contact* pc, char name[])
{

	for (int i = 0; i < pc->size; i++)
	{
		if (strcmp(name, pc->data[i].name) == 0)
		{
			return i;          //�ҵ���
		}
	}

	return -1;                //�Ҳ���
}

////ɾ����ϵ��
		/*��̬�汾*/
//void DelContact(Contact* pc)
//{
//	assert(pc);
//
//	if (pc->size == 0)
//	{
//		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
//		return;
//	}
//
//	//��Ϊ�������ɾ��
//	//1.�ҵ�Ҫɾ������
//	char name[MAX_NAME] = { '\0'};
//	printf("����Ҫɾ����ϵ�˵�����>��");
//	scanf("%s", name);
//
//	int del = 0;             //��¼Ҫɾ����λ��
//	int flag = 0;            //��ʾҪɾ������ϵ���Ƿ����
//	for (int i = 0; i < pc->size; i++)
//	{
//		if (strcmp(pc->data[i].name, name) == 0)
//		{
//			del = i;
//			flag = 1;
//			break;
//		}
//	}
//	if (flag == 0)
//	{
//		printf("Ҫɾ������ϵ�˲�����\n");
//		return;
//	}
// 
//	//ɾ������Ϊdel����ϵ��
//	for (int i = del; i < pc->size; i++)
//	{
//		pc->data[i] = pc->data[i + 1];
//	}
// 
//	pc->size--;
//	printf("�ɹ�ɾ����ϵ��\n");
//}

void DelContact(Contact* pc)
{
	assert(pc);
	if (pc->size == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
	}

	char name[MAX_NAME] = { 0 };
	printf("������Ҫɾ��������>��");
	scanf("%s", &name);
	//�ҵ�Ҫɾ������
	int del = FindByName(pc, name);
	if (del == -1)
	{
		printf("���˲�����\n");
		return;
	}

	//ɾ������i����
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
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ���ҵ�����>��");
	scanf("%s", name);

	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("���˲�����\n");
	}
	else
	{
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-30s\n",
			"����", "����", "�Ա�", "�绰", "��ַ");
		
		//��ӡ����
		printf("%-10s\t%-4d\t%-5s\t%-12s\t%-30s\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].addr);
	}
}

//�޸���ϵ��
void ModifyContact(Contact* pc)
{
	assert(pc);

	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);

	if (pos == -1)
		printf("Ҫ�޸ĵ��˲�����\n");
	else
	{
		printf("����������:>");
		scanf("%s", pc->data[pos].name);
		printf("����������:>");
		scanf("%d", &(pc->data[pos].age));
		printf("�������Ա�:>");
		scanf("%s", pc->data[pos].sex);
		printf("������绰:>");
		scanf("%s", pc->data[pos].tele);
		printf("�������ַ:>");
		scanf("%s", pc->data[pos].addr);

		printf("�޸ĳɹ�\n");
	}
}

//��ʾ��ϵ��
void ShowContact(Contact* pc)
{
	assert(pc);

	printf("%-10s\t%-4s\t%-5s\t%-12s\t%-30s\n",
		"����", "����", "�Ա�", "�绰", "��ַ");

	for (int i = 0; i < pc->size; i++)
	{
		printf("%-10s\t%-4d\t%-5s\t%-12s\t%-30s\n"
			, pc->data[i].name
			, pc->data[i].age
			, pc->data[i].sex
			, pc->data[i].tele
			, pc->data[i].addr
		);
	}
}

//��������������
int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

void SortContact(Contact* pc)
{
	qsort(pc->data, pc->size, sizeof(PeoInfo), cmp_by_name);
	printf("����ɹ�\n");
}

void DestroyContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->size = 0;
}

void SaveContact(Contact* pc)
{
	FILE* pf = fopen("contact.dat", "wb");
	if (pf == NULL)
	{
		perror("SaveContact");
		return;
	}

	//д����
	for (int i = 0; i < pc->size; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pf);
	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}