#include "Stack.h"

void test()
{
	Stack st;
	StackInit(&st);
	//入栈1 2 3 4 5
	//StackPush(&st, 1);
	//StackPush(&st, 2);
	//StackPush(&st, 3);
	//StackPush(&st, 4);
	//StackPush(&st, 5);

	//printf("%d", StackTop(&st));

	//printf("%d", StackSize(&st));

	if (StackEmpty(&st))
	{
		printf("栈为空！\n");
	}
	else
	{
		printf("栈非空！\n");
	}

	//StackPop(&st);
	//StackPop(&st);
	//StackPop(&st);
	//StackPop(&st);
	//StackPop(&st);
	//StackPop(&st);


	//while (!StackEmpty(&st))
	//{
	//	printf("%d ", StackTop(&st));
	//	StackPop(&st);
	//}
	//printf("\n");

	StackDestroy(&st);
}

int main()
{
	test();
	return 0;
}