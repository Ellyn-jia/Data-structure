#include"SList.h"

SListNode* BuySListNode(SLDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
void SListPushBack(SListNode** pplist, SLDataType x)
{
	SListNode* newNode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newNode;
	}
	else
	{
		SListNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}
void SListPushFront(SListNode** pplist, SLDataType x)
{
	SListNode* newNode = BuySListNode(x);
	newNode->next = *pplist;
	*pplist = newNode;
}
void SListPopBack(SListNode** pplist)
{
	if (*pplist == NULL)
	{
		return;
	}
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SListNode* tail = *pplist;
		SListNode* prev = NULL;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		prev->next = NULL;
		free(tail);
	}
}
void SListPopFront(SListNode** pplist)
{
	if (*pplist == NULL)
	{
		return;
	}
	else
	{
		SListNode* head = *pplist;
		*pplist = (*pplist)->next;
		free(head);
	}
}


void SListInsertAfter(SListNode**pplist, SListNode* pos, SLDataType x)
{
	
}