#include"SeqList.h"

void SeqListInit(SeqList* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListDestory(SeqList* ps)
{
	assert(ps);

	free(ps);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListPrint(SeqList* ps)
{
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListCheck(SeqList* ps)
{
	if (ps->size == ps->capacity)
	{
		size_t newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		ps->a = (SLDataType *)realloc(ps->a, newcapacity * sizeof(SLDataType));
		ps->capacity = newcapacity;
	}
}

void SeqListPushBack(SeqList* ps, SLDataType x)//Î²²å
{
	assert(ps);

	SeqListCheck(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPushFront(SeqList* ps, SLDataType x)//Í·²å
{
	assert(ps);
	SeqListCheck(ps);

	size_t end = ps->size;
	while (end)
	{
		ps->a[end] = ps->a[end - 1];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}


void SeqListPopFront(SeqList* ps)//Í·É¾
{
	assert(ps);
	size_t start = 0;
	while (start < ps->size - 1)
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	ps->size--;
}


void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	ps->size--;
}


void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps);
	assert(pos <= ps->size);
	SeqListCheck(ps);

	size_t end = ps->size;
	while (end > pos)
	{
		ps->a[end] = ps->a[end - 1];
	}
	ps->a[pos] = x;
	ps->size++;
}

void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	assert(pos <= ps->size);

	size_t start = pos;
	while (start < ps->size-1)
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	ps->size--;
}

int SeqListFind(SeqList* ps, SLDataType x)
{
	for (size_t i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}