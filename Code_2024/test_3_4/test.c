#define _CRT_SECURE_NO_WARNINGS 1
//author:付平权

#include "game.h"

void menu()
{
	printf("--------------------------\n");
	printf("|         1. play        |\n");
	printf("|         0. exit        |\n");
	printf("--------------------------\n");
}

void game()
{
	char board[ROW][COL] = { 0 };
	InitBoard(board,ROW,COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);

	//下棋
	char ret = 0;
	while (1)
	{
		//玩家下棋
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret = IsWin(board,ROW,COL);
		if (ret != 'C')
			break;

		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;	
	}		

	system("cls");

	if (ret == '*')
		printf("恭喜你赢啦\n");
	else if (ret == '#')
		printf("电脑赢\n");
	else
		printf("平局\n");
}


int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);

	return 0;
}