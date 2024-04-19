#define _CRT_SECURE_NO_WARNINGS 1

#include "snake.h"

void SetPos(short x, short y)
{
	//获得标准输出设备的句柄
	HANDLE houtput = NULL;
	houtput = GetStdHandle(STD_OUTPUT_HANDLE);

	//定位光标的位置
	COORD pos = { x, y };
	SetConsoleCursorPosition(houtput, pos);
}

void WelcomeToGame()
{
	SetPos(40, 14);
	wprintf(L"欢迎来到贪吃蛇小游戏\n");
	SetPos(42, 20);
	system("pause");
	system("cls");
	SetPos(25, 14);
	wprintf(L"用 ↑. ↓ . ← . → 来控制蛇的移动，按F3加速，F4减速\n");
	SetPos(25, 15);
	wprintf(L"加速得高分\n");

	SetPos(42, 20);
	system("pause");
	system("cls");
}

void CreateMap()
{
	//上
	int i = 0;
	for (i = 0; i < 29; i++)
	{
		wprintf(L"%lc", WALL);
	}

	//下
	SetPos(0, 26);
	for (i = 0; i < 29; i++)
	{
		wprintf(L"%lc", WALL);
	}

	//左
	for (i = 1; i <= 25; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", WALL);
	}

	//右
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
		//头插
		if (ps->_pSnake == NULL)  //空链表
		{
			ps->_pSnake = cur;
		}
		else //非空
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

	//设置贪吃蛇属性
	ps->_dir = RIGHT;       //默认向右
	ps->_status = OK;
	ps->_score = 0;
	ps->_food_weight = 10;
	ps->_sleep_time = 200;  //单位毫秒
}

void CreateFood(pSnake ps)
{
	int x = 0;
	int y = 0;

	//生成x是2的倍数
	//x：2~54  y: 1~25
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

	//创建食物的节点
	pSnakeNode pFood = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pFood == NULL)
	{
		perror("CreateFood::malloc");
		return;
	}

	pFood->x = x;
	pFood->y = y;
	pFood->next = NULL;

	SetPos(x, y);//定位位置
	wprintf(L"%lc", FOOD);

	ps->_pFood = pFood;
}

void GameStart(pSnake ps)
{
	//0. 先设置窗口的大小，再光标隐藏
	system("mode con cols=100 lines=30");
	system("title 贪吃蛇");
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	//隐藏光标操作
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(houtput, &CursorInfo);  //获取控制台 光标信息
	CursorInfo.bVisible = false;                 //隐藏控制台光标
	SetConsoleCursorInfo(houtput, &CursorInfo);  //设置控制台光标状态

	//1. 打印欢迎界面和功能介绍
	WelcomeToGame();
	//2. 绘制地图
	CreateMap();
	//3. 创建蛇
	InitSnake(ps);
	//4. 创建食物
	CreateFood(ps);
	//5. 设置游戏的相关信息
}

void GameRun(pSnake ps)
{
	SetPos(70, 10);
	wprintf(L"贪吃蛇小游戏");
	SetPos(65, 12);
	wprintf(L"按↑ ↓ ← →来控制蛇的移动");
	SetPos(68, 14);
	wprintf(L"按F3加速，F4减速");
	getchar();
}