#include "Stack.h"

int main()
{
	Stack st;
	STInit(&st);

	STPush(&st, 1);
	STPush(&st, 2);
	STPush(&st, 3);
	STPush(&st, 4);
	STPush(&st, 5);
	STPush(&st, 6);
	STPush(&st, 7);


	while (!STEmpty(&st))
	{
		printf("%d ", STTop(&st));
		STPop(&st);
	}

	STDestroy(&st);

	return 0;
}