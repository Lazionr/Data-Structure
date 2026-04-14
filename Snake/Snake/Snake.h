#pragma once
#include <Windows.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POS_X 24
#define POS_Y 5
#define WALL L'□'
#define BODY  L'●'
#define FOOD L'★'

//类型的声明

//蛇的方向
enum DIRECTION
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

//蛇的状态
enum GAME_STATUS
{
	OK,
	KILL_BY_WALL,//撞墙
	KILL_BY_SELF,//撞到自己
	END_NORMAL   //正常退出
};

//蛇身的节点类型
typedef struct SnakeNode
{
	//坐标
	int x;
	int y;
	//指向下一个节点的指针
	struct SnakeNode* next;
}SnakeNode,*pSnakeNode;

//贪吃蛇
typedef struct Snake
{
	pSnakeNode _pSnake;//指向蛇头的指针
	pSnakeNode _pFood;//指向食物节点的指针
	enum DIRECTION _dir;//蛇的方向
	enum GAME_STATUS _status;//游戏状态
	int _food_weight;//一个
	int _score;
	int _sleep_time;//休息时间，时间越短，速度越快，时间越长，速度越慢

}Snake,*pSnake;
//*pSnake 等价于 struct Snake* 

//函数的声明

//定位光标位置
void SetPos(short x, short y);

//一、初始化游戏
void GameStart(pSnake ps);

//1.欢迎界面
void WelcomeToGame();

//2.绘制地图
void CreatMap();

//3.初始化蛇身
void InitSnake(pSnake ps);

//4.创建食物
void CreateFood(pSnake ps);

//二、游戏运行逻辑
void GameRun(pSnake ps);

//1.蛇的移动
void SnakeMove(pSnake ps);

//2.判断下一个坐标处是否是食物
bool NextIsFood(pSnakeNode pNext,pSnake ps);

//3.判断下一个位置是否是食物，是就吃掉
void EatFood(pSnakeNode pNext, pSnake ps);

//4.不是食物
void NoFood(pSnakeNode pNext, pSnake ps);

//5.检测是否撞墙
void KillByWall(pSnake ps);

//6.检测是否撞到自己
void KillBySelf(pSnake ps);

//三、结束游戏-善后工作
void GameEnd(pSnake ps);
