
#include<stdio.h>
#include<malloc.h>

typedef int HeapDataType;
typedef struct Heap{
	HeapDataType* a;
	int size;
	int capacity;

}Heap;

void HeapCreat(Heap* hp, HeapDataType* a, int n);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HeapDataType x);
void HeapPop(Heap* hp);
HeapDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);
void HeapPrint(Heap* hp);