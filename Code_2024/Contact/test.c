#include "contact.h"

void menu()
{
	printf("\n");
	printf("*********************************\n");
	printf("***    1.add       2.del      ***\n");
	printf("***    3.search    4.modify   ***\n");
	printf("***    5.show      6.sort     ***\n");
	printf("***    0.exit                 ***\n");
	printf("*********************************\n");
}

void test_contact1()
{
	int input = 0;
	//首先要有通讯录
	Contact con;    //con为结构体变量
	InitContact(&con);
	do
	{
		menu();
		printf("请选择>：");
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			SaveContact(&con);
			DestroyContact(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("输入非法，请重新选择>：");
			break;
		}
	} while (input);
}


int main()
{
	test_contact1();
	return 0;
}