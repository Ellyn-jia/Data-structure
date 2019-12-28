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

//返回链表中间元素
typedef struct ListNode ListNode;
struct ListNode* middleNode(struct ListNode* head){
	int count = 0;
	ListNode* cur = head;
	ListNode* Node = head;
	while (cur)
	{
		cur = cur->next;
		count++;
	}
	count = count / 2;
	while (count)
	{
		Node = Node->next;
		count--;
	}
	return Node;
}











class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL || k <= 0)
		{
			return NULL;
		}
		ListNode* first = pListHead;
		ListNode* second = pListHead;
		while (k && second)
		{
			second = second->next;
			k--;
		}
		if (k > 0)
		{
			return NULL;
		}
		while (second)
		{
			first = first->next;
			second = second->next;
		}
		return first;
	}
};


typedef struct ListNode ListNode;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	if (l1 == NULL && l2 == NULL)
		return NULL;
	ListNode* head1 = l1;
	ListNode* head2 = l2;
	while (head1 && head2)
	{
		ListNode* next1 = head1->next;
		ListNode* next2 = head2->next;
		if (head1->val <= head2->val)
		{
			head1->next = head2;
			head2->next = next1;
			head1 = next1;
			head2 = next2;
		}
		else
		{

		}
	}
	return l1;
}

