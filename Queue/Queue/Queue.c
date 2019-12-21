#include "Queue.h"

void QueueInit(Queue* q)
{
	q->end = q->first = NULL;
}
void QueuePush(Queue* q, QDataType x)
{
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->data = x;
	newNode->next = NULL;
	if (q->end == NULL)
	{
		q->first = q->end = newNode;
	}
	else
	{
		q->end->next = newNode;
		q->end = newNode;
	}
}
void QueuePop(Queue* q)
{
	if (q->first->next == NULL)
	{
		free(q->first);
		q->first = q->end = NULL;
	}
	else
	{
		QueueNode* next = q->first->next;
		free(q->first);
		q->first = next;
	}
}
QDataType QueueFirst(Queue* q)
{
	assert(q);
	return q->first->data;
}
QDataType QueueEnd(Queue* q)
{
	return q->end->data;
}
int QueueSize(Queue* q)//队列有效元素个数
{
	int count = 0;
	QueueNode* cur = q->first;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
int QueueEmpty(Queue* q)//空 1   非空 0
{
	return q->first == NULL ? 1 : 0;
}
void QueueDestory(Queue* q)
{
	QueueNode* cur = q->first;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->end = q->first = NULL;
}