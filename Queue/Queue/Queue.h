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
int QueueSize(Queue* q);//������ЧԪ�ظ���
int QueueEmpty(Queue* q);//�� 1   �ǿ� 0
void QueueDestory(Queue* q);