#pragma once
#include<stdio.h>
#include<assert.h>



typedef int SLDataType;
typedef struct Seqlist
{
	SLDataType* a;
	size_t size;
	size_t capacity;
}SeqList;



//对数据的增删查改

void SeqListInit(SeqList* ps);

void SeqListDestory(SeqList* ps);

void SeqListPrint(SeqList* ps);


//插入
void SeqListPushBack(SeqList* ps, SLDataType x);
void SeqListPushFront(SeqList* ps, SLDataType x);