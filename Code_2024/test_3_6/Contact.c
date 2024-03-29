#define _CRT_SECURE_NO_WARNINGS 1
//author:付平权

#include "Contact.h"

//静态版本
//void InitContact(Contact* pc)
//{
//	assert(pc);
//	memset(pc->data, 0, sizeof(pc->data));
//	pc->size = 0;
//}

int CheckCapacity(Contact* pc)
{
	if (pc->size == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			perror("CheckCapacity");
			return 0;
		}
		else
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("增容成功\n");
			return 1;
		}
	}
	return 1;
}


void LoadContact(Contact* pc)
{
	//打开文件
	FILE* pf = fopen("contact.dat", "rb");
	if (pf == NULL)
	{
		perror("LoadContact");
		return;
	}

	//读文件
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{
		if (0 == CheckCapacity(pc))
			return;
		pc->data[pc->size] = tmp;
		pc->size++;
	}

	//关闭文件
	fclose(pf);
	pf = NULL;
}


//动态版本
void InitContact(Contact* pc)
{
	assert(pc);
	pc->data = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		perror("InitContact");
		return;
	}
	pc->size = 0;
	pc->capacity = DEFAULT_SZ;

	//文件中保存的信息加载到通讯录中
	LoadContact(pc);
}


#if 0
//静态版本
//增加联系人
void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->size == MAX)
	{
		printf("通讯录已满，无法添加\n");
		return;
	}

	printf("请输入姓名:>");
	scanf("%s", pc->data[pc->size].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->size].age));
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->size].sex);
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->size].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->size].addr);

	pc->size++;
	printf("成功增加联系人\n");
}
#endif

//动态的版本
void AddContact(Contact* pc)
{
	assert(pc);

	if (0 == CheckCapacity(pc))
	{
		return;
	}

	printf("请输入名字:>");
	scanf("%s", pc->data[pc->size].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->size].age));
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->size].sex);
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->size].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->size].addr);

	pc->size++;
	printf("成功增加联系人\n");
}


//显示联系人
void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-10s\t%-4s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
	//打印数据
	for (i = 0; i < pc->size; i++)
	{
		printf("%-10s\t%-4d\t%-5s\t%-12s\t%-30s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}

//
////删除联系人
//void DelContact(Contact* pc)
//{
//	assert(pc);
//	if (pc->size == 0)
//	{
//		printf("联系人为空，无法删除\n");
//		return;
//	}
//	
//	char name[MAX_NAME] = { 0 };
//	printf("请输入要删除的联系人名字:>");
//	scanf("%s", name);
//
//	//找到要删除的人
//	int i = 0;
//	int del = 0;
//	int flag = 0;
//	for (i = 0; i < pc->size; i++)
//	{
//		if (strcmp(pc->data[i].name, name) == 0)
//		{
//			del = i;
//			flag = 1;
//			break;
//		}
//	}
//
//	if (flag == 0)
//	{
//		printf("要删除的人不存在\n");
//		return;
//	}
//
//	//删除对应的联系人
//	for (i = del; i <pc->size-1 ; i++)
//	{
//		pc->data[i] = pc->data[i + 1];
//	}
//
//	pc->size--;
//
//	printf("成功删除联系人\n");
//}

static int FindByName(const Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->size; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;  //找到了
		}
	}
	return -1; //找不到
}



void DelContact(Contact* pc)
{
	if (pc->size == 0)
	{
		printf("通讯录为空，无法删除\n");
		return;
	}
	char name[MAX_NAME] = { 0 };
	assert(pc);
	//删除
	printf("请输入要删除的人名字:>");
	scanf("%s", name);

	//找到要删除的人
	int del = FindByName(pc, name);
	if (del == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	int i = 0;
	//删除坐标位del的联系人
	for (i = del; i < pc->size - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->size--;

	printf("成功删除联系人\n");
}


void SearchContact(const Contact* pc)
{
	assert(pc);

	char name[MAX_NAME] = { 0 };
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
		printf("要找的人不存在\n");
	else
	{
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-30s\n", "名字", "年龄", "性别", "电话", "地址");
		//打印数据
		printf("%-10s\t%-4d\t%-5s\t%-12s\t%-30s\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].addr);
	}
}


void ModifyContact(Contact* pc)
{
	assert(pc);

	char name[MAX_NAME] = { 0 };
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要修改的联系人不存在\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", pc->data[pos].name);
		printf("请输入年龄:>");
		scanf("%d", &(pc->data[pos].age));
		printf("请输入性别:>");
		scanf("%s", pc->data[pos].sex);
		printf("请输入电话:>");
		scanf("%s", pc->data[pos].tele);
		printf("请输入地址:>");
		scanf("%s", pc->data[pos].addr);

		printf("修改成功\n");
	}
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
	//写数据
	int i = 0;
	for (i = 0; i < pc->size; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pf);
	}

	//关闭文件
	fclose(pf);
	pf = NULL;
}

//void qsort(void* base, size_t num, size_t size,
//	int (*compar)(const void*, const void*));

//按照名字来排序
int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

void SortContact(Contact* pc)
{
	qsort(pc->data, pc->size, sizeof(PeoInfo), cmp_by_name);
	printf("排序成功\n");
}