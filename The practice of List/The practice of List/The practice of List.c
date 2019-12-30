//��ת����  �� ע��  ����Ϊ�� 
//����ֱ�ӽ�����ԭ�ط�������1->2->3       1<-2<-3
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

//���������м�Ԫ��
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


