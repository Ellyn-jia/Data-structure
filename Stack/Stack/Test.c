#include "Stack.h"

void Test()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	printf("%d\n", StackTop(&s));
	StackPop(&s);
	printf("%d\n", StackTop(&s));
	while (!StackEmpty(&s))
	{
		printf("%d\n", StackTop(&s));
		StackPop(&s);
	}
	StackDestory(&s);
}

int main()
{
	Test();
	return 0;
}