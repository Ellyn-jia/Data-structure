#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef int QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
	struct QueueNode* first;
	struct QueueNode* end;
}Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, QDataType x);
void QueuePop(Queue* q);
QDataType QueueFirst(Queue* q);
QDataType QueueEnd(Queue* q);
int QueueSize(Queue* q);//队列有效元素个数
int QueueEmpty(Queue* q);//空 1   非空 0
void QueueDestory(Queue* q);