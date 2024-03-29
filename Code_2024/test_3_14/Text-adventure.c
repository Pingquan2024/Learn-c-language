#define _CRT_SECURE_NO_WARNINGS 1
//author:付平权

#include "Text-adventure.h"

// 初始化游戏地图
void initializeGame(char map[MAP_SIZE][MAP_SIZE]) {
    // 随机生成宝藏和陷阱的位置
    srand((unsigned int)time(NULL));
    int treasureX = rand() % MAP_SIZE;
    int treasureY = rand() % MAP_SIZE;
    int trapX = rand() % MAP_SIZE;
    int trapY = rand() % MAP_SIZE;

    // 初始化地图
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = EMPTY;
        }
    }

    // 放置宝藏和陷阱
    map[treasureX][treasureY] = TREASURE;
    map[trapX][trapY] = TRAP;
}

// 显示游戏地图
void displayMap(char map[MAP_SIZE][MAP_SIZE]) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

// 移动玩家
void movePlayer(char map[MAP_SIZE][MAP_SIZE], int* playerX, int* playerY, char move) {
    switch (move) {
    case 'w':
        if (*playerX > 0 && checkMove(map, *playerX - 1, *playerY, move)) {
            map[*playerX][*playerY] = EMPTY;
            *playerX -= 1;
            map[*playerX][*playerY] = PLAYER;
        }
        break;
    case 's':
        if (*playerX < MAP_SIZE - 1 && checkMove(map, *playerX + 1, *playerY, move)) {
            map[*playerX][*playerY] = EMPTY;
            *playerX += 1;
            map[*playerX][*playerY] = PLAYER;
        }
        break;
    case 'a':
        if (*playerY > 0 && checkMove(map, *playerX, *playerY - 1, move)) {
            map[*playerX][*playerY] = EMPTY;
            *playerY -= 1;
            map[*playerX][*playerY] = PLAYER;
        }
        break;
    case 'd':
        if (*playerY < MAP_SIZE - 1 && checkMove(map, *playerX, *playerY + 1, move)) {
            map[*playerX][*playerY] = EMPTY;
            *playerY += 1;
            map[*playerX][*playerY] = PLAYER;
        }
        break;
    }
}

// 检查玩家移动是否合法
int checkMove(char map[MAP_SIZE][MAP_SIZE], int playerX, int playerY, char move) {
    if (map[playerX][playerY] == TRAP) {
        printf("You fell into a trap! Game Over.\n");
        return 0;
    }
    else if (map[playerX][playerY] == TREASURE) {
        printf("Congratulations! You found the treasure!\n");
        return 0;
    }
    else {
        return 1;
    }
}

// 开始游戏
void playGame() {
    char map[MAP_SIZE][MAP_SIZE];
    int playerX = 0;
    int playerY = 0;

    initializeGame(map);
    map[playerX][playerY] = PLAYER;

    char move;
    while (1) {
        system("cls"); // 清空控制台（适用于 Windows 系统）
        displayMap(map);

        printf("Enter your move (w/a/s/d): ");
        scanf(" %c", &move);

        movePlayer(map, &playerX, &playerY, move);

        if (map[playerX][playerY] == TREASURE || map[playerX][playerY] == TRAP) {
            break;
        }
    }
}
