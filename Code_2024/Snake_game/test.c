#define _CRT_SECURE_NO_WARNINGS 1

#include "snake.h"

//int main()
//{
//	//设置控制台的相关属性
//	system("mode con cols=100 lines=30");
//	system("title 贪吃蛇");
//
//	return 0;
//}

//完成游戏的测试逻辑
void test()
{
	//创建贪吃蛇
	Snake snake = { 0 };
	//初始化游戏
	//1. 打印欢迎界面
	//2. 功能介绍
	//3. 绘制地图
	//4. 创建蛇
	//5. 创建食物
	//6. 设置游戏的相关信息
	GameStart(&snake);

	//运行游戏
	GameRun(&snake);
	//结束游戏
	//GameEend();
}

int main()
{
	//设置适配本地环境
	setlocale(LC_ALL, "");
	srand((unsigned int)time(NULL));
	test();

	return 0;
}