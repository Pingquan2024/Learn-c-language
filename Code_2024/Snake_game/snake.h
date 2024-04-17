#pragma once

#include <stdbool.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

//���͵�����

//�ߵķ���
enum DIRECTION
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

//�ߵ�״̬
//������ײǽ��ײ���Լ��������˳�
enum GAME_STATUS
{
	OK, //����
	KILL_BY_WALL, //ײǽ
	KILL_BY_SELF, //ײ���Լ�
	END_NORMAL    //�����˳�
};

//����Ľڵ�����
typedef struct SnakeNode
{
	//����
	int x;
	int y;
	//ָ����һ���ڵ��ָ��
	struct SnakeNode* next;
}SnakeNode, * pSnakeNode;

//typedef struct SnakeNode* pSnakeNode;


//̰����
typedef struct Snake
{
	pSnakeNode _pSnake;         //ָ����ͷ��ָ��
	pSnakeNode _pFood;          //ָ��ʳ��ڵ��ָ��
	enum DIRECTION _dir;	    //�ߵķ���
	enum GAME_STATUS _status;   //��Ϸ��״̬
	int _food_weight;           //һ��ʳ��ķ���
	int _score;				    //�ܳɼ�
	int _sleep_time;			//��Ϣʱ�䣬ʱ��Խ�̣��ٶ�Խ�죬ʱ��Խ�����ٶ�Խ��
}Snake, * pSnake;

//����������
//��Ϸ�ĳ�ʼ��
void GameStart(pSnake ps);
//��ӭ����Ĵ�ӡ
void WelcomeToGame();

//������ͼ
void CreateMap();
