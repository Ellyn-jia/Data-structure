#include"SeqList.h"

void TestSeqList()
{
	SeqList s;
	SeqListInit(&s);

	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPrint(&s);

	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 4);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPrint(&s);

	SeqListInsert(&s, 2, 7);
	SeqListPrint(&s);

	SeqListErase(&s, 2);
	SeqListPrint(&s);

	SeqListDestory(&s);
}

int main()
{
	TestSeqList();
	return 0;
}