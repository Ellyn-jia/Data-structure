#include"SeqList.h"

void SeqListinit(SeqList* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->size = 20;
	ps->capacity = 20;
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
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListPushBack(SeqList* ps, SLDataType x)
{

}