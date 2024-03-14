#pragma once
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef GAME_H
#define GAME_H

// 游戏地图的大小
#define MAP_SIZE 10

// 地图上的不同元素
#define EMPTY '0'
#define PLAYER 'P'   //玩家位置
#define TREASURE 'T' //宝藏
#define TRAP 'X'     //陷进

// 函数声明
void initializeGame(char map[MAP_SIZE][MAP_SIZE]);
void displayMap(char map[MAP_SIZE][MAP_SIZE]);
void movePlayer(char map[MAP_SIZE][MAP_SIZE], int* playerX, int* playerY, char move);
int checkMove(char map[MAP_SIZE][MAP_SIZE], int playerX, int playerY, char move);
void playGame();

#endif
