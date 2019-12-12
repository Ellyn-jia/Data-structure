#include<stdio.h>
#include<malloc.h>

typedef int LTDataType;
typedef struct ListNode{
	LTDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;

ListNode* BuyNode(LTDataType x);
ListNode* ListCreat();
void ListDestory(ListNode* plist);
void ListPrint(ListNode* plist);
void ListPushBack(ListNode* plist, LTDataType x);
void ListPushFront(ListNode* plist, LTDataType x);
void ListPopBack(ListNode* plist);
void ListPopFront(ListNode* plist);
ListNode* ListFind(ListNode* plist, LTDataType x);
void ListInsert(ListNode* pos, LTDataType x);
void ListErase(ListNode* pos);



