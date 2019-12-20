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
		int newcapacity = p->capacity == 0 ? 4 : p->capacity * 2;
		p->a = (STDataType*)realloc(p->a,sizeof(STDataType)*newcapacity);
		p->capacity = newcapacity;
	}
	p->a[p->top] = x;
	p->top++;
}
STDataType StackTop(Stack* p)
{
	assert(p);
	return p->a[p->top - 1];
}
void StackPop(Stack* p)
{
	assert(p && p->top != 0);
	p->top--;
}
int StackEmpty(Stack* p)
{
	assert(p);
	return p->top == 0 ? 1 : 0;
}
int StackSize(Stack* p)
{
	return p->top;
}
void StackDestory(Stack* p)
{
	free(p->a);
	p->a = NULL;
	p->capacity = 0;
	p->top = 0;
}
