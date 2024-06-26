#define _CRT_SECURE_NO_WARNINGS 1
//author:付平权

//#include "Text-adventure.h"
//
//
//void InitializeGame(char board[ROWS][COLS], int numTreasures, int numTraps)
//{
//	int i, j;
//
//	// 初始化棋盘为'.'
//	for (i = 0; i < ROWS; i++)
//	{
//		for (j = 0; j < COLS; j++)
//		{
//			board[i][j] = '.';
//		}
//	}
//
//	// 随机放置宝藏
//	for (i = 0; i < numTreasures; i++)
//	{
//		int row, col;
//		do
//		{
//			row = rand() % ROWS;
//			col = rand() % COLS;
//		} while (board[row][col] != '.'); // 仅在空格处放置宝藏
//		board[row][col] = 'T';
//	}
//
//	// 随机放置陷阱
//	for (i = 0; i < numTraps; i++)
//	{
//		int row, col;
//		do
//		{
//			row = rand() % ROWS;
//			col = rand() % COLS;
//		} while (board[row][col] != '.'); // 仅在空格处放置陷阱
//		board[row][col] = 'X';
//	}
//
//	// 玩家放置的起始位置
//	board[0][0] = 'P';
//}
//
//
//void DisplayMap(char board[ROWS][COLS])
//{
//	int i = 0;
//	for (i = 0; i < ROWS; i++)
//	{
//		int j = 0;
//		for (j = 0; j < COLS; j++)
//		{
//			printf(" %c ", board[i][j]);
//			if (j < COLS - 1)
//			{
//				printf("|");
//			}
//		}
//		printf("\n");
//		//打印分割线
//		if (i < ROWS - 1)
//		{
//			int j = 0;
//			for (j = 0; j < COLS; j++)
//			{
//				printf("---");
//				if (j < COLS - 1)
//					printf("|");
//			}
//
//		}
//		printf("\n");
//	}
//}
//
//int MovePlayer(char board[ROWS][COLS], char move)
//{
//	int newRow, newCol;
//	int currentRow, currentCol;
//
//	//找到玩家的当前位置
//	for (int i = 0; i < ROWS; i++)
//	{
//		for (int j = 0; j < COLS; j++)
//		{
//			if (board[i][j] == 'P')
//			{
//				currentRow = i;
//				currentCol = j;
//			}
//		}
//	}
//
//	//计算基于移动的新位置
//	switch (move)
//	{
//	case 'w':
//		newRow = currentRow - 1;
//		newCol = currentCol;
//		break;
//	case 'a':
//		newRow = currentRow;
//		newCol = currentCol - 1;
//		break;
//	case 's':
//		newRow = currentRow + 1;
//		newCol = currentCol;
//		break;
//	case 'd':
//		newRow = currentRow;
//		newCol = currentCol + 1;
//		break;
//	default:
//		printf("Invalid move!\n");
//		return 0;
//	}
//
//	//检查新位置是否合法
//	if (CheckMove(board, newRow, newCol))
//	{
//		//移动玩家到新位置
//		board[currentRow][currentCol] = ' ';
//		board[newRow][newCol] = 'P';
//		return 1;
//	}
//	else
//	{
//		printf("无效的移动!\n");
//		return 0;
//	}
//}
//
//int CheckMove(char board[ROWS][COLS], int newRow, int newCol)
//{
//	//检查新位置是否在边界内
//	if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS)
//	{
//		//检查新位置是否为陷阱
//		if (board[newRow][newCol] != 'X')
//		{
//			return 1; //合法移动
//		}
//	}
//	return 0; //无效移动
//}
//
//int CheckWin(char board[ROWS][COLS], int numTreasures)
//{
//	int treasuresFound = 0;
//
//	//清点发现的宝藏
//	for (int i = 0; i < ROWS; i++)
//	{
//		for (int j = 0; j < COLS; j++)
//		{
//			if (board[i][j] == 'P')
//			{
//				//检查相邻的单元是否有宝藏
//				if (i > 0 && board[i - 1][j] == 'T') 
//					treasuresFound++;
//				if (j > 0 && board[i][j - 1] == 'T') 
//					treasuresFound++;
//				if (i < ROWS - 1 && board[i + 1][j] == 'T') 
//					treasuresFound++;
//				if (j < COLS - 1 && board[i][j + 1] == 'T') 
//					treasuresFound++;
//			}
//		}
//	}
//
//	//检查所有宝藏是否被发现
//	if (treasuresFound == numTreasures)
//	{
//		return 1; //获胜条件满足
//	}
//	return 0; //获胜条件不满足
//}


#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
#define NUM 100
    char bar[NUM + 1];
    memset(bar, '\0', sizeof(bar));

    const char* lable = "|/-\\";

    int i = 0;
    while (i <= 100) {
        printf("\033[31m[%-100s][%3d%%][%c]\r", bar, i, lable[i % 4]);
        fflush(stdout);
        bar[i] = '=';
        i++;
        usleep(50000);
    }
    printf("\n");

}

