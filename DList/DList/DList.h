#include<stdio.h>
#include<malloc.h>
typedef int LTDataType;
typedef struct ListNode{
	LTDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;

ListNode* ListCreat();


