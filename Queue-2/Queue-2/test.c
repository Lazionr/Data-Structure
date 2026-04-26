#include "Queue.h"

void test()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	printf("%d", QueueBack(&q));

	//printf("%d", QueueFront(&q));

	//while (!QueueEmpty(&q))
	//{
	//	printf("%d ", q.phead->val);
	//	QueuePop(&q);
	//}
	//printf("\n");

	QueueDestroy(&q);
	
}


int main()
{
	test();
	return 0;
}