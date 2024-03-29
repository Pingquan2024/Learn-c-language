#define _CRT_SECURE_NO_WARNINGS 1
//author:付平权

#include "Contact.h"

void menu()
{
	printf("------------------------------\n");
	printf("|     1.Add     2.Del        |\n");
	printf("|     3.Search  4.Modify     |\n");
	printf("|     5.Show    6.sort       |\n");
	printf("|     0.exit                 |\n");
	printf("------------------------------\n");

}

int main()
{	
	int input = 0;
	//首先得有通讯录
	Contact con;
	InitContact(&con);
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
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
			/*printf("退出通讯录\n");*/
			SaveContact(&con);
			DestroyContact(&con);
			printf("退出通讯录\n");
			break;
		default :
			printf("选择错误，重新选择\n");
			break;

		}
	} while (input);


}
