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



//�ϲ�������������


// ����һ���µĴ�ͷ������ÿ��ȡС��β��

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

typedef struct ListNode ListNode;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	if (l1 == NULL)
	{
		return l2;
	}
	else if (l2 == NULL)
	{
		return l1;
	}
	else
	{
		ListNode* head = NULL;
		ListNode* tail = NULL;
		head = tail = (ListNode*)malloc(sizeof(ListNode));
		head->next = NULL;
		while (l1 && l2)
		{
			tail->next = NULL;
			if (l1->val < l2->val)
			{
				tail->next = l1;
				tail = tail->next;
				l1 = l1->next;
			}
			else
			{
				tail->next = l2;
				tail = tail->next;
				l2 = l2->next;
			}
		}
		if (l2)
		{
			tail->next = l2;
		}
		if (l1)
		{
			tail->next = l1;
		}
		ListNode* L = head->next;
		free(head);
		return L;
	}
}



//����ָ�


/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		// write code here
		if (pHead == NULL)
			return pHead;
		struct ListNode* lHead, *gHead, *lTail, *gTail;
		lHead = lTail = (struct ListNode*)malloc(sizeof(struct ListNode));
		gHead = gTail = (struct ListNode*)malloc(sizeof(struct ListNode));
		struct ListNode* cur = pHead;
		if (cur->val < x)
		{
			lHead->next = cur;
			cur = cur->next;
			lTail = lTail->next;
		}
		else
		{
			gHead->next = cur;
			cur = cur->next;
			gTail = gTail->next;
		}
		lTail->next = gHead->next;
		gTail->next = NULL;
		pHead = lTail->next;
		free(lHead);
		free(gHead);
		return pHead;
	}
};






