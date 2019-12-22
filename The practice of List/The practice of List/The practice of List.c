//反转链表  ： 注意  链表为空 
//可以直接将链表原地反过来，1->2->3       1<-2<-3
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

typedef struct ListNode ListNode;
struct ListNode* reverseList(struct ListNode* head){
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode* prev = head;
	ListNode* cur = head->next;
	ListNode* next = head->next->next;
	prev->next = NULL;
	while (next)
	{
		cur->next = prev;
		prev = cur;
		cur = next;
		next = next->next;
	}
	cur->next = prev;
	return cur;
}