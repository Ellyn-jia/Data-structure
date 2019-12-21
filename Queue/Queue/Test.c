#include "Queue.h"

void Test()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	printf("%d\n", QueueFirst(&q));
	QueuePop(&q);
	printf("%d\n", QueueFirst(&q));
	while (!QueueEmpty(&q))
	{
		printf("%d\n", QueueFirst(&q));
		QueuePop(&q);
	}
	QueueDestory(&q);
}

int main()
{
	Test();
	return 0;
}