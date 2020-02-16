

// 括号匹配

typedef char STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}Stack;

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
		p->a = (STDataType*)realloc(p->a, sizeof(STDataType)*newcapacity);
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


bool isValid(char * s){
	Stack st;
	StackInit(&st);
	char symbol[3][2] = { '(', ')', '[', ']', '{', '}' };
	while (*s)
	{
		int i = 0;
		for (i = 0; i < 3; i++)
		{
			if (*s == symbol[i][0])
			{
				StackPush(&st, *s);
				s++;
				break;
			}
		}
		if (i == 3)
		{
			if (StackEmpty(&st) == 1)
				return false;
			char top = StackTop(&st);
			int j = 0;
			for (j = 0; j < 3; j++)
			{
				if (*s == symbol[j][1])
				{
					if (top == symbol[j][0])
					{
						s++;
						StackPop(&st);
						break;
					}
					else
					{
						return false;
					}
				}
			}
		}
	}
	if (StackEmpty(&st) == 1)
		return true;
	else
		return false;


}









//用队列实现栈
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




typedef struct {
	Queue q1;
	Queue q2;

} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {

	MyStack* p = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&p->q1);
	QueueInit(&p->q2);
	return p;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	if (QueueEmpty(&obj->q1) != 0)
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	Queue* EmptyQueue = &obj->q1;
	Queue* AntiEmptyQueue = &obj->q2;
	if (QueueEmpty(&obj->q2))
	{
		EmptyQueue = &obj->q2;
		AntiEmptyQueue = &obj->q1;
	}
	while (QueueSize(AntiEmptyQueue) > 1)
	{
		QueuePush(EmptyQueue, QueueFirst(AntiEmptyQueue));
		QueuePop(AntiEmptyQueue);

	}
	int top = QueueFirst(AntiEmptyQueue);
	QueuePop(AntiEmptyQueue);
	return top;

}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	Queue* EmptyQueue = &obj->q1;
	Queue* AntiEmptyQueue = &obj->q2;
	if (QueueEmpty(&obj->q2))
	{
		EmptyQueue = &obj->q2;
		AntiEmptyQueue = &obj->q1;
	}

	return QueueEnd(AntiEmptyQueue);

}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {

	if (QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2))
		return true;
	else
		return false;
}

void myStackFree(MyStack* obj) {
	QueueDestory(&obj->q1);
	QueueDestory(&obj->q2);
	free(obj);

}

/**
* Your MyStack struct will be instantiated and called as such:
* MyStack* obj = myStackCreate();
* myStackPush(obj, x);

* int param_2 = myStackPop(obj);

* int param_3 = myStackTop(obj);

* bool param_4 = myStackEmpty(obj);

* myStackFree(obj);
*/








//用栈实现队列
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}Stack;

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
		p->a = (STDataType*)realloc(p->a, sizeof(STDataType)*newcapacity);
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


typedef struct {
	Stack PushS;
	Stack PopS;

} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* pQueue = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&pQueue->PushS);
	StackInit(&pQueue->PopS);
	return pQueue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->PushS, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	if (StackEmpty(&obj->PopS))
	{
		while (!StackEmpty(&obj->PushS))
		{
			StackPush(&obj->PopS, StackTop(&obj->PushS));
			StackPop(&obj->PushS);
		}
	}
	int top = StackTop(&obj->PopS);
	StackPop(&obj->PopS);
	return top;

}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->PopS))
	{
		while (!StackEmpty(&obj->PushS))
		{
			StackPush(&obj->PopS, StackTop(&obj->PushS));
			StackPop(&obj->PushS);
		}
	}
	return StackTop(&obj->PopS);

}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	if (StackEmpty(&obj->PushS) && StackEmpty(&obj->PopS))
		return true;
	else
		return false;

}

void myQueueFree(MyQueue* obj) {
	StackDestory(&obj->PushS);
	StackDestory(&obj->PopS);
	free(obj);
}

/**
* Your MyQueue struct will be instantiated and called as such:
* MyQueue* obj = myQueueCreate();
* myQueuePush(obj, x);

* int param_2 = myQueuePop(obj);

* int param_3 = myQueuePeek(obj);

* bool param_4 = myQueueEmpty(obj);

* myQueueFree(obj);
*/









//设计循环队列
typedef struct {
	int* queue;
	int front;
	int last;
	int k;

} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* p = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	p->queue = (int*)malloc(sizeof(int)*(k + 1));
	p->front = 0;
	p->last = 0;
	p->k = k;

	return p;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if ((obj->last + 1) % (obj->k + 1) == (obj->front))
		return false;
	obj->queue[obj->last++] = value;
	if (obj->last == obj->k + 1)
		obj->last = 0;
	return true;

}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (obj->last == obj->front)
		return false;
	obj->front++;
	if (obj->front == obj->k + 1)
		obj->front = 0;
	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if (obj->front == obj->last)
		return -1;
	else
		return obj->queue[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (obj->front == obj->last)
		return -1;
	if (obj->last == 0)
		return obj->queue[obj->k];
	else
		return obj->queue[obj->last - 1];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->front == obj->last;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {

	return (obj->last + 1) % (obj->k + 1) == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->queue);
	free(obj);

}

/**
* Your MyCircularQueue struct will be instantiated and called as such:
* MyCircularQueue* obj = myCircularQueueCreate(k);
* bool param_1 = myCircularQueueEnQueue(obj, value);

* bool param_2 = myCircularQueueDeQueue(obj);

* int param_3 = myCircularQueueFront(obj);

* int param_4 = myCircularQueueRear(obj);

* bool param_5 = myCircularQueueIsEmpty(obj);

* bool param_6 = myCircularQueueIsFull(obj);

* myCircularQueueFree(obj);
*/

