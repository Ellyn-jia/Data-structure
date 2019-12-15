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
void ListDestory(ListNode* phead);
void ListPrint(ListNode* phead);
void ListPushBack(ListNode* phead, LTDataType x);
void ListPushFront(ListNode* phead, LTDataType x);
void ListPopBack(ListNode* phead);
void ListPopFront(ListNode* phead);
ListNode* ListFind(ListNode* phead, LTDataType x);
void ListInsert(ListNode* pos, LTDataType x);
void ListErase(ListNode* pos);



