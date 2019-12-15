#include"DList.h"

void Test()
{
	ListNode* phead = ListCreat();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPrint(phead);
	ListPopBack(phead);
	ListPrint(phead);


}

int main()
{
	Test();
	return 0;
}