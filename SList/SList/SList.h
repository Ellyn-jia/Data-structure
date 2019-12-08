#pragma once

#include<stdio.h>
#include<malloc.h>

typedef int SLDataType;
typedef struct SListNode{
	SLDataType data;
	struct SListNode* next;
}SListNode;


SListNode* BuySListNode(SLDataType x);
void SListPrint(SListNode* plist);
void SListPushBack(SListNode** pplist, SLDataType x);
void SListPushFront(SListNode** pplist, SLDataType x);
void SListPopBack(SListNode** pplist);
void SListPopFront(SListNode** pplist);
void SListInsertAfter(SListNode* pos, SLDataType x);
void SListEraseAfter(SListNode* pos);
