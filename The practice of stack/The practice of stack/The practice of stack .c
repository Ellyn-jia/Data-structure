

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

