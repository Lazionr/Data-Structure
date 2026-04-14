#include "Snake.h"

//定位光标位置
void SetPos(short x, short y)
{
    //获取标准输出设备的句柄
    HANDLE houtput = NULL;
    houtput = GetStdHandle(STD_OUTPUT_HANDLE);

    //定位光标位置
    COORD pos = { x,y };
    SetConsoleCursorPosition(houtput, pos);
}

//欢迎界面
void WelcomeToGame()
{
    SetPos(35, 15);
    wprintf(L"欢迎来到贪吃蛇小游戏！\n");
    SetPos(37, 25);
    system("pause");
    system("cls");
    SetPos(26, 15);
    wprintf(L"用↑.↓.←.→ 来控制蛇的移动，按F3加速，F4减速\n");
    SetPos(26, 16);
    wprintf(L"加速能够得到更高的分数！\n");
    SetPos(37, 25);
    system("pause");
    system("cls");
}

//2.绘制地图
//27行58列的棋盘
void CreatMap()
{
    //上
    for (int i = 0; i < 29; i++)
    {
        wprintf(L"%lc", L'□');
    }
    //下
    SetPos(0, 26);
    for (int i = 0; i < 29; i++)
    {
        wprintf(L"%lc", L'□');
    }
    //左
    for (int i = 1; i <= 25; i++)
    {
        SetPos(0, i);
        wprintf(L"%lc", L'□');
    }
    //右
    for (int i = 1; i <= 25; i++)
    {
        SetPos(56, i);
        wprintf(L"%lc", L'□');
    }
}

//3.初始化蛇身
void InitSnake(pSnake ps)
{
    pSnakeNode cur = NULL;
    for (int i = 0; i < 5; i++)
    {
        cur = (pSnakeNode)malloc(sizeof(SnakeNode));
        if (cur == NULL)
        {
            perror("InitSnake()::malloc\n");
            return;
        }
        //将链表串起来
        cur->x = POS_X + 2 * i;
        cur->y = POS_Y;
        cur->next = NULL;

        //头插法插入链表
        //空链表
        if (ps->_pSnake == NULL)
        {
            ps->_pSnake = cur;
        }
        //非空链表
        else
        {
            //头插
            cur->next = ps->_pSnake;
            ps->_pSnake = cur;
        }
    }
    cur = ps->_pSnake;
    while (cur)
    {
        //定位光标至当前位置
        SetPos(cur->x, cur->y);
        wprintf(L"%lc", BODY);
        cur = cur->next;
    }

    //设置贪吃蛇的属性
    ps->_dir = RIGHT;
    ps->_score = 0;
    ps->_food_weight = 10;
    ps->_sleep_time = 200;//单位是ms
    ps->_status = OK;

}

//4.创建食物
void CreateFood(pSnake ps)
{
    //先随机生成坐标
    //墙内部 x坐标必须是偶数 不能和蛇的坐标重复
    int x = 0;
    int y = 0;
    //x:2-54 y:1-25
again:
    do
    {
        //x必须是偶数
        x = rand() % 53 + 2;
        y = rand() % 25 + 1;
    } while (x % 2);

    //不能和蛇的坐标重复
    pSnakeNode cur = ps->_pSnake;
    while (cur)
    {
        if (cur->x == x && cur->y == y) goto again;
        cur = cur->next;
    }
    
    //创建食物节点
    pSnakeNode pFood = (pSnakeNode)malloc(sizeof(SnakeNode));
    if (pFood == NULL)
    {
        perror("CreateFood()::malloc");
        return;
    }
    pFood->x = x;
    pFood->y = y;
    pFood->next = NULL;

    //定位到食物位置
    SetPos(x, y);
    wprintf(L"%lc", FOOD);

    ps->_pFood = pFood; ;
}

//初始化游戏
void GameStart(pSnake ps)
{
	//初始化游戏
    //0.先设置窗口的大小，然后再隐藏光标
    system("mode con cols=100 lines=30");
    system("title 贪吃蛇");
    HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
    //隐藏光标操作
    CONSOLE_CURSOR_INFO cursor_info;
    GetConsoleCursorInfo(houtput, &cursor_info);
    cursor_info.bVisible = false;
    SetConsoleCursorInfo(houtput, &cursor_info);

    //1.打印欢迎界面和功能介绍
    WelcomeToGame();
    //2.绘制地图
    CreatMap();
    //3.初始化蛇身
    InitSnake(ps);
    //4.创建食物
    CreateFood(ps);
}


//打印帮助信息
void PrintHelpInfo()
{
    SetPos(64, 10);
    wprintf(L"%ls", L"不能穿墙，不能咬到自己！");

    SetPos(64, 11);
    wprintf(L"%ls", L"用↑.↓.←.→ 来控制蛇的移动");

    SetPos(64, 12);
    wprintf(L"%ls", L"按F3加速，F4减速");

    SetPos(64, 13);
    wprintf(L"%ls", L"按ESC退出游戏，按空格暂停游戏");

    SetPos(75, 15);
    wprintf(L"%ls", L"Lazion");

}

#define KEY_PRESS(vk) ((GetAsyncKeyState(vk)&1) ? 1 : 0)

//暂停
void Pause()
{
    while (1)
    {
        Sleep(200);
        if (KEY_PRESS(VK_SPACE)) break;
    }
}

//2.判断下一个坐标处是否是食物
bool NextIsFood(pSnakeNode pNext, pSnake ps)
{
    //pNext：指向下一个位置的节点的指针
    //ps：指向贪吃蛇的指针

    return (ps->_pFood->x == pNext->x && ps->_pFood->y == pNext->y);
}


//3.判断下一个位置是否是食物，是就吃掉
void EatFood(pSnakeNode pNext, pSnake ps)
{
    //头插
    ps->_pFood->next = ps->_pSnake;
    ps->_pSnake = ps->_pFood;

    //由于是两个malloc，导致虽然此时pNext存储的坐标与食物坐标相同，但仍是不同的内存块
    //释放下一个位置的节点
    free(pNext);
    pNext = NULL;

    pSnakeNode cur = ps->_pSnake;
    //打印
    while (cur)
    {
        SetPos(cur->x, cur->y);
        wprintf(L"%lc", BODY);
        cur = cur->next;
    }
    ps->_score += ps->_food_weight;
    //吃掉之后再次创建食物
    CreateFood(ps);
}

//4.不是食物
void NoFood(pSnakeNode pNext, pSnake ps)
{
    //头插
    pNext->next = ps->_pSnake;
    ps->_pSnake = pNext;

    //释放掉最后一个节点
    pSnakeNode cur = ps->_pSnake;
    while (cur->next->next)
    {
        SetPos(cur->x, cur->y);
        wprintf(L"%lc", BODY);
        cur = cur->next;
    }
    //把最后一个节点打印成空格
    SetPos(cur->next->x, cur->next->y);
    printf("  ");
    //释放最后一个节点
    free(cur->next);
    //把倒数第二个节点的地址置为空
    cur->next = NULL;
}

//5.检测是否撞墙
void KillByWall(pSnake ps)
{
    if (ps->_pSnake->x == 0 || ps->_pSnake->x == 56 ||
        ps->_pSnake->y == 0 || ps->_pSnake->y == 26)
    {
        ps->_status = KILL_BY_WALL;
    }
}

//6.检测是否撞到自己
void KillBySelf(pSnake ps)
{
    //遍历蛇，看是否有与蛇头重复的坐标
    pSnakeNode cur = ps->_pSnake->next;
    while (cur)
    {
        if (cur->x == ps->_pSnake->x && cur->y == ps->_pSnake->y)
        {
            ps->_status = KILL_BY_SELF;
            break;
        }
        cur = cur->next;
    }

}

//1.蛇的移动
void SnakeMove(pSnake ps)
{
    //创建一个节点，表示蛇即将到达的下一个地方
    pSnakeNode pNextNode = (pSnakeNode)malloc(sizeof(SnakeNode));
    if (pNextNode == NULL)
    {
        perror("SnakeMove()::malloc\n");
        return;
    }

    switch (ps->_dir)
    {
    case UP:
        pNextNode->x = ps->_pSnake->x;
        pNextNode->y = ps->_pSnake->y - 1;
        break;
    case DOWN:
        pNextNode->x = ps->_pSnake->x;
        pNextNode->y = ps->_pSnake->y + 1;
        break;
    case LEFT:
        pNextNode->x = ps->_pSnake->x - 2;
        pNextNode->y = ps->_pSnake->y;
        break;
    case RIGHT:
        pNextNode->x = ps->_pSnake->x + 2;
        pNextNode->y = ps->_pSnake->y;
        break;
    }

    //判断下一个坐标处是否是食物
    if (NextIsFood(pNextNode,ps))
    {
        //3.判断下一个位置是否是食物，是就吃掉
        EatFood(pNextNode, ps);
    }
    else
    {
        //不是食物
        NoFood(pNextNode, ps);
    }

    //检测是否撞墙
    KillByWall(ps);
    //检测是否撞到自己
    KillBySelf(ps);

}

//运行游戏
void GameRun(pSnake ps)
{
    //打印帮助信息
    PrintHelpInfo();
    do
    {
        //打印总分数和食物的分值
        SetPos(64, 7);
        printf("总分数：%d", ps->_score);
        SetPos(64, 8);
        printf("当前食物的分数：%2d", ps->_food_weight);

        //检测按键
        if (KEY_PRESS(VK_UP) && ps->_dir != DOWN)
        {
            ps->_dir = UP;
        }
        else if (KEY_PRESS(VK_DOWN) && ps->_dir != UP)
        {
            ps->_dir = DOWN;
        }
        else if (KEY_PRESS(VK_LEFT) && ps->_dir != RIGHT)
        {
            ps->_dir = LEFT;
        }
        else if (KEY_PRESS(VK_RIGHT) && ps->_dir != LEFT)
        {
            ps->_dir = RIGHT;
        }
        else if (KEY_PRESS(VK_SPACE))
        {
            //暂停
            Pause();
        }
        else if (KEY_PRESS(VK_ESCAPE))
        {
            //正常退出游戏
            ps->_status = END_NORMAL;
        }
        else if (KEY_PRESS(VK_F3))
        {
            //加速
            if (ps->_sleep_time > 80)
            {
                ps->_sleep_time -= 30;
                ps->_food_weight += 2;
            }
        }
        else if (KEY_PRESS(VK_F4))
        {
            //减速
            if (ps->_food_weight > 2)
            {
                ps->_sleep_time += 30;
                ps->_food_weight -= 2;
            }
        }
        //贪吃蛇走一步
        SnakeMove(ps);
        Sleep(ps->_sleep_time);

    } while (ps->_status == OK);
}

//三、结束游戏-善后工作
void GameEnd(pSnake ps)
{
    SetPos(20, 11);
    switch (ps->_status)
    {
    case END_NORMAL :
        printf("您主动结束游戏！\n");
        break;
    case KILL_BY_WALL:
        printf("您撞到墙上，游戏结束！\n");
        break;
    case KILL_BY_SELF:
        printf("您撞到自己，游戏结束！\n");
        break;
    }
    //释放蛇身的链表
    pSnakeNode cur = ps->_pSnake;
    while (cur)
    {
        pSnakeNode del = cur;
        cur = cur->next;
        free(del);
    }
}
