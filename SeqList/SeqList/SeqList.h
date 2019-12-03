#pragma once
#include<stdio.h>
#include<assert.h>
#include<malloc.h>



typedef int SLDataType;
typedef struct Seqlist
{
	SLDataType* a;
	size_t size;
	size_t capacity;
}SeqList;

void SeqListCheck(SeqList* ps);


//对数据的增删查改

void SeqListInit(SeqList* ps);

void SeqListDestory(SeqList* ps);

void SeqListPrint(SeqList* ps);


//插入
void SeqListPushBack(SeqList* ps, SLDataType x);
void SeqListPushFront(SeqList* ps, SLDataType x);

//删除
void SeqListPopFront(SeqList* ps);
void SeqListPopBack(SeqList* ps);

//顺序表查找
int SeqListFind(SeqList* ps, SLDataType x);

//顺序表在pos位置插入值x
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x);

//删除顺序表pos位置的值
void SeqListErase(SeqList* ps, size_t pos);