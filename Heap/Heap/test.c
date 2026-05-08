#include "Heap.h"

int main()
{
	HP hp;
	HPInit(&hp);

	HPPush(&hp, 1);
	HPPush(&hp, 2);
	HPPush(&hp, 3);
	HPPush(&hp, 4);
	HPPush(&hp, 5);
	HPPush(&hp, 6);

	while (!HPEmpty(&hp))
	{
		printf("%d ", HPTop(&hp));
		HPPop(&hp);
	}
	printf("\n");

	HPDestroy(&hp);

	return 0;
}




