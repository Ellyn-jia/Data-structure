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
	return head;
}
void ListDestory(ListNode* phead)
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}
void ListPrint(ListNode* phead)
{
	if (phead->next == phead)
	{
		printf("NULL\n");
	}
	else
	{
		ListNode* cur = phead->next;
		while (cur != phead)
		{
			printf("%d ", cur->data);
			cur = cur->next;
		}
	}
	printf("\n");
}
void ListPushBack(ListNode* phead, LTDataType x)
{
	ListNode* newNode = BuyNode(x);
	ListNode* prev = phead->prev;
	phead->prev = newNode;
	newNode->next = phead;
	newNode->prev = prev;
	prev->next = newNode;
}
void ListPushFront(ListNode* phead, LTDataType x)
{
	ListNode* newNode = BuyNode(x);
	ListNode* first = phead->next;
	phead->next = newNode;
	newNode->prev = phead;
	first->prev = newNode;
	newNode->next = first;
}
void ListPopBack(ListNode* phead)
{
	ListNode* tail = phead->prev;
	phead->prev = tail->prev;
	tail->prev->next = phead;
	free(tail);
}
void ListPopFront(ListNode* phead)
{
	ListNode* first = phead->next;
	ListNode* second = first->next;
	phead->next = first->next;
	second->prev = phead;
	free(first);
}
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data != x)
		{
			cur = cur->next;
		}
		else
		{
			return cur;
		}
	}
	return NULL;
}
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* prev = pos->prev;
	ListNode* newNode = BuyNode(x);
	prev->next = newNode;
	newNode->prev = prev;
	pos->prev = newNode;
	newNode->next = pos;
}
void ListErase(ListNode* pos)
{
	ListNode* prev = pos->prev;
	prev->next = pos->next;
	pos->next->prev = prev;
	free(pos);
}
