#define _CRT_SECURE_NO_WARNINGS 1
//author:付平权

//#include "Text-adventure.h"
//
//int main() 
//{
//    char board[ROWS][COLS];
//    int numTreasures, numTraps;
//    char move;
//
//    printf("欢迎来到文字冒险游戏!\n");
//
//    enum GraDifficulty difficulty;
//    
//    //选择难度水平
//    printf("选择难度等级(1, 2, or 3): ");
//    scanf("%d", &difficulty);
//
//    switch (difficulty)
//    {
//    case JuniorPlayer:
//        numTreasures = 2;
//        numTraps = 1;
//        break;
//    case IntermediatePlayer:
//        numTreasures = 3;
//        numTraps = 2;
//        break;
//    case AdvancedPlayer:
//        numTreasures = 4;
//        numTraps = 3;
//        break;
//    default:
//        printf("无效的难度等级，设置为默认值(1)\n");
//        numTreasures = 2;
//        numTraps = 1;
//        break;
//    }
//
//    InitializeGame(board, numTreasures, numTraps);
//
//    while (1) 
//    {
//        DisplayMap(board);
//
//        //询问玩家的移动
//        printf("Enter your move (w/a/s/d): ");
//        scanf(" %c", &move);
//
//        if (MovePlayer(board, move)) 
//        {
//            //检查胜利条件
//            if (CheckWin(board, numTreasures)) 
//            {
//                DisplayMap(board);
//                printf("恭喜! 你发现了所有宝藏!\n");
//                break;
//            }
//        }
//    }
//
//    return 0;
//}

//struct BinaryTreeNode
//{
//	int data;
//	struct BinaryTreeNode* left;
//	struct BinaryTreeNode* right;
//};
//
//struct QueueNode
//{
//	struct QueueNode* next;
//	struct BinaryTreeNode* data;
//};
//
//struct Queue
//{
//	struct QueueNode* phead;
//	struct QueueNode* ptail;
//	int size;
//};
