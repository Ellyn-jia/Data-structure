#include"Stack.h"

void StackInit(Stack* p)
{
	assert(p);
	p->a = NULL;
	p->capacity = 0;
	p->top = 0;
}

void StackPush(Stack* p, STDataType x)
{
	assert(p);

	if (p->top == p->capacity)
	{

	}
}