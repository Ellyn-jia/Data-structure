#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}Stack;

void StackInit(Stack* p);
void StackPush(Stack* p, STDataType x);
void StackPrint(Stack* p);
STDataType StackTop(Stack* p);
void StackPop(Stack* p);
int StackEmpty(Stack* p);//���ջ�Ƿ�Ϊ�գ��շ���1���ǿշ���0
int StackSize(Stack* p);
void StackDestory(Stack* p);