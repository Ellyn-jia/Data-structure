#include"DList.h"

void Test()
{
	ListNode* phead = ListCreat();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPrint(phead);

	ListPushFront(phead, 3);
	ListPushFront(phead, 4);	
	ListPrint(phead);

	ListPopBack(phead);
	ListPrint(phead);

	ListPopFront(phead);
	ListPrint(phead);
	
	ListNode* pos =  ListFind(phead, 1);
	ListInsert(pos, 8);
	ListPrint(phead);

	ListErase(pos);
	ListPrint(phead);
	ListDestory(phead);
}

int main()
{
	Test();
	return 0;
}