#include<stdio.h>
//ÒÆ³öÁ´±íÔªËØ
struct ListNode {
	int val;
	struct ListNode *next;
	
};
typedef struct ListNode ListNode;
struct ListNode* removeElements(struct ListNode* head, int val){
	if (head == NULL)
		return NULL;
	while (head != NULL && head->val == val)
	{
		head = head->next;
	}
	ListNode* cur = head;
	ListNode* prev = NULL;
	while (cur != NULL)
	{
		if (cur->val == val)
		{
			prev->next = cur->next;
			free(cur);
			cur = prev->next;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}