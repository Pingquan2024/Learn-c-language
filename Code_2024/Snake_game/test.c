#define _CRT_SECURE_NO_WARNINGS 1

#include "snake.h"

//int main()
//{
//	//���ÿ���̨���������
//	system("mode con cols=100 lines=30");
//	system("title ̰����");
//
//	return 0;
//}

//�����Ϸ�Ĳ����߼�
void test()
{
	//����̰����
	Snake snake = { 0 };
	//��ʼ����Ϸ
	//1. ��ӡ��ӭ����
	//2. ���ܽ���
	//3. ���Ƶ�ͼ
	//4. ������
	//5. ����ʳ��
	//6. ������Ϸ�������Ϣ
	GameStart(&snake);

	//������Ϸ
	GameRun(&snake);
	//������Ϸ
	//GameEend();
}

int main()
{
	//�������䱾�ػ���
	setlocale(LC_ALL, "");
	srand((unsigned int)time(NULL));
	test();

	return 0;
}