#include"DList.h"

ListNode* BuyNode(LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
ListNode* ListCreat()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->next = head;
	head->prev = head;
}
void ListDestory(ListNode* plist);
void ListPrint(ListNode* plist);
void ListPushBack(ListNode* plist, LTDataType x);
void ListPushFront(ListNode* plist, LTDataType x);
void ListPopBack(ListNode* plist);
void ListPopFront(ListNode* plist);
ListNode* ListFind(ListNode* plist, LTDataType x);
void ListInsert(ListNode* pos, LTDataType x);
void ListErase(ListNode* pos);


