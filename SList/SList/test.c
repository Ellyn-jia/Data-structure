#include"SList.h"

void Test()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);

	SListPrint(plist);

	SListPushFront(&plist, 6);
	SListPushFront(&plist, 7);
	SListPushFront(&plist, 8);
	SListPushFront(&plist, 9);
	SListPushFront(&plist, 0);

	SListPrint(plist);

	SListPopFront(&plist);
	SListPopFront(&plist);

	SListPrint(plist);

	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);

	SListPrint(plist);

	SListPrint(plist);
}

int main()
{
	Test();
}