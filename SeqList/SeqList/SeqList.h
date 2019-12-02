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



//�����ݵ���ɾ���

void SeqListInit(SeqList* ps);

void SeqListDestory(SeqList* ps);

void SeqListPrint(SeqList* ps);


//����
void SeqListPushBack(SeqList* ps, SLDataType x);
void SeqListPushFront(SeqList* ps, SLDataType x);