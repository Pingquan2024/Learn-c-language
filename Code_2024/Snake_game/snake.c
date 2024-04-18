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
		wprintf(L"%lc", L'��');
	}

	//��
	SetPos(0, 26);
	for (i = 0; i < 29; i++)
	{
		wprintf(L"%lc", L'��');
	}

	//��
	for (i = 1; i <= 25; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", L'��');
	}

	//��
	for (i = 1; i <= 25; i++)
	{
		SetPos(56, i);
		wprintf(L"%lc", L'��');
	}

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
	//InitSnake(ps);
	//4. ����ʳ��

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