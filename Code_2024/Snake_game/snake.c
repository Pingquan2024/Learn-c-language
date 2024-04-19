#define _CRT_SECURE_NO_WARNINGS 1

#include "snake.h"

void SetPos(short x, short y)
{
	//��ñ�׼����豸�ľ��
	HANDLE houtput = NULL;
	houtput = GetStdHandle(STD_OUTPUT_HANDLE);

	//��λ����λ��
	COORD pos = { x, y };
	SetConsoleCursorPosition(houtput, pos);
}

void WelcomeToGame()
{
	SetPos(40, 14);
	wprintf(L"��ӭ����̰����С��Ϸ\n");
	SetPos(42, 20);
	system("pause");
	system("cls");
	SetPos(25, 14);
	wprintf(L"�� ��. �� . �� . �� �������ߵ��ƶ�����F3���٣�F4����\n");
	SetPos(25, 15);
	wprintf(L"���ٵø߷�\n");

	SetPos(42, 20);
	system("pause");
	system("cls");
}

void CreateMap()
{
	//��
	int i = 0;
	for (i = 0; i < 29; i++)
	{
		wprintf(L"%lc", WALL);
	}

	//��
	SetPos(0, 26);
	for (i = 0; i < 29; i++)
	{
		wprintf(L"%lc", WALL);
	}

	//��
	for (i = 1; i <= 25; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", WALL);
	}

	//��
	for (i = 1; i <= 25; i++)
	{
		SetPos(56, i);
		wprintf(L"%lc", WALL);
	}

}

void InitSnake(pSnake ps)
{
	pSnakeNode cur = NULL;
	for (int i = 0; i < SNAKELENGTH; i++)
	{
		cur = (pSnakeNode)malloc(sizeof(SnakeNode));
		if (cur == NULL)
		{
			perror("InitSnake()::malloc");
			return;
		}

		cur->next = NULL;
		cur->x = POS_X + 2;
		cur->y = POS_Y;
		//ͷ��
		if (ps->_pSnake == NULL)  //������
		{
			ps->_pSnake = cur;
		}
		else //�ǿ�
		{
			cur->next = ps->_pSnake;
			ps->_pSnake = cur;
		}
	}

	cur = ps->_pSnake;
	while (cur != NULL)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}

	//����̰��������
	ps->_dir = RIGHT;       //Ĭ������
	ps->_status = OK;
	ps->_score = 0;
	ps->_food_weight = 10;
	ps->_sleep_time = 200;  //��λ����
}

void CreateFood(pSnake ps)
{
	int x = 0;
	int y = 0;

	//����x��2�ı���
	//x��2~54  y: 1~25
again:
	do
	{
		x = rand() % 53 + 2;
		y = rand() % 25 + 1;
	} while (x % 2 != 0);

	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		if (x == cur->x || y == cur->y)
		{
			goto again;
		}
		cur = cur->next;
	}

	//����ʳ��Ľڵ�
	pSnakeNode pFood = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pFood == NULL)
	{
		perror("CreateFood::malloc");
		return;
	}

	pFood->x = x;
	pFood->y = y;
	pFood->next = NULL;

	SetPos(x, y);//��λλ��
	wprintf(L"%lc", FOOD);

	ps->_pFood = pFood;
}

void GameStart(pSnake ps)
{
	//0. �����ô��ڵĴ�С���ٹ������
	system("mode con cols=100 lines=30");
	system("title ̰����");
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	//���ع�����
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(houtput, &CursorInfo);  //��ȡ����̨ �����Ϣ
	CursorInfo.bVisible = false;                 //���ؿ���̨���
	SetConsoleCursorInfo(houtput, &CursorInfo);  //���ÿ���̨���״̬

	//1. ��ӡ��ӭ����͹��ܽ���
	WelcomeToGame();
	//2. ���Ƶ�ͼ
	CreateMap();
	//3. ������
	InitSnake(ps);
	//4. ����ʳ��
	CreateFood(ps);
	//5. ������Ϸ�������Ϣ
}

void GameRun(pSnake ps)
{
	SetPos(70, 10);
	wprintf(L"̰����С��Ϸ");
	SetPos(65, 12);
	wprintf(L"���� �� �� ���������ߵ��ƶ�");
	SetPos(68, 14);
	wprintf(L"��F3���٣�F4����");
	getchar();
}