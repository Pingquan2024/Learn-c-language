#include "contact.h"

menu()
{
	printf("*********************************\n");
	printf("***    1.add       2.del      ***\n");
	printf("***    3.search    4.modify   ***\n");
	printf("***    5.show      6.sort     ***\n");
	printf("***    0.exit                 ***\n");
	printf("*********************************\n");
}

void test_contact1()
{
	menu();
	int input = 0;
	//����Ҫ��ͨѶ¼
	Contact con;    //conΪ�ṹ�����
	InitContact(&con);
	do
	{
		printf("��ѡ��>��");
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
			//SortContcat(&con);


			break;
		case EXIT:
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("����Ƿ���������ѡ��>��");
			break;
		}
	} while (input);
}


int main()
{
	test_contact1();
	return 0;
}