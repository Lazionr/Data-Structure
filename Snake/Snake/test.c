#include <locale.h>
#include "Snake.h"

#define _CRT_SECURE_NO_WARNINGS

//游戏测试逻辑
void test()
{
	char ch = 0;
	do
	{
		system("cls");
		//创建贪吃蛇
		Snake snake = { 0 };

		//一、初始化游戏
		//0.隐藏光标
		//1.打印欢迎界面和功能介绍
		//2.绘制地图
		//3.创建蛇
		//4.创建实物
		//5.设置游戏的相关信息
		GameStart(&snake);

		//二、游戏运行逻辑
		GameRun(&snake);

		//三、结束游戏-善后工作
		GameEnd(&snake);
		SetPos(20, 14);

		printf("再来一局吗?(Y/N):");
		scanf_s(" %c", &ch);
		getchar();
	} while (ch == 'Y' || ch == 'y');
	SetPos(0,27);
}

int main()
{
	//设置适配本地环境
	setlocale(LC_ALL, "");
	srand((unsigned)time(0));
	test();

	return 0;
}