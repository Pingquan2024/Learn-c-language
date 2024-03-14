#pragma once
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef GAME_H
#define GAME_H

// ��Ϸ��ͼ�Ĵ�С
#define MAP_SIZE 10

// ��ͼ�ϵĲ�ͬԪ��
#define EMPTY '0'
#define PLAYER 'P'   //���λ��
#define TREASURE 'T' //����
#define TRAP 'X'     //�ݽ�

// ��������
void initializeGame(char map[MAP_SIZE][MAP_SIZE]);
void displayMap(char map[MAP_SIZE][MAP_SIZE]);
void movePlayer(char map[MAP_SIZE][MAP_SIZE], int* playerX, int* playerY, char move);
int checkMove(char map[MAP_SIZE][MAP_SIZE], int playerX, int playerY, char move);
void playGame();

#endif
