#include "contact.h"

//初始化通讯录
void InitContact(Contact* pc)
{
	assert(pc);
	memset(pc->data, 0, sizeof(pc->data));
	pc->size = 0;
}

//增加联系人
void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->size == MAX)
	{
		printf("通讯录已满，无法添加\n");
		return;
	}

	printf("请输入名字>：");
	scanf("%s", pc->data[pc->size].name);
	printf("请输入性别>：");
	scanf("%s", pc->data[pc->size].sex);	
	printf("请输入年龄>：");
	scanf("%d", &(pc->data[pc->size].age));
	printf("请输入电话>：");
	scanf("%s", pc->data[pc->size].tele);
	printf("请输入地址>：");
	scanf("%s", pc->data[pc->size].addr);

	pc->size++;
	printf("成功增加联系人\n");
}

//删除联系人
void DelContact(Contact* pc)
{
	assert(pc);

	if (pc->size == 0)
	{
		printf("通讯录为空，无法删除\n");
		return;
	}

	//不为空则进行删除
	//1.找到要删除的人
	char name[MAX_NAME] = { '\0'};
	printf("输入要删除联系人的名字>：");
	scanf("%s", name);

	int del = 0;             //记录要删除的位置
	int flag = 0;            //表示要删除的联系人是否存在
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
		printf("要删除的联系人不存在\n");
		return;
	}
	//删除坐标为del的联系人
	for (int i = del; i < pc->size; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->size--;

	printf("成功删除联系人\n");
}

int FindByName(const Contact* pc,char name[])
{
	assert(pc);

	for (int i = 0; i < pc->size; i++)
	{
		if (strcmp(name, pc->data[i].name) == 0)
		{
			return i;   //找到了
		}
	}

	return -1;        //找不到了
}

//查找联系人
void SearchContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找的姓名>：");
	scanf("%s", name);
	
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("此人不存在\n");
	}
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

//修改联系人
void ModifyContact(Contact* pc)
{
	assert(pc);

	char name[MAX_NAME] = { 0 };
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
		printf("要修改的人不存在\n");
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

//显示联系人
void ShowContact(Contact* pc)
{
	assert(pc);

	printf("%-10s\t%-4s\t%-5s\t%-12s\t%-30s\n", "名字", "年龄", "性别", "电话", "地址");
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

//按年龄排序
void SortContact(Contact* pc)
{

}

void DestroyContact(Contact* pc)
{
	free(pc->data);
	//pc->data = NULL;
	//pc->capacity = 0;
	pc->size = 0;
}