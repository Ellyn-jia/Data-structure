#include <stdio.h>
#include <assert.h>

typedef int STDataType;
typedef struct Stack
{
	struct Stack* a;
	int top;
	int capacity;
}Stack;

void StackInit(Stack* p);
void StackPush(Stack* p, STDataType x);