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



//�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ
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
		ListNode* cur = pHead;
		ListNode* less, *bigger, *ps, *pb;
		ps = less = (ListNode*)malloc(sizeof(ListNode));
		pb = bigger = (ListNode*)malloc(sizeof(ListNode));
		while (cur)
		{
			if (cur->val < x)
			{
				ps->next = cur;
				ps = ps->next;
				cur = cur->next;
			}
			else
			{
				pb->next = cur;
				pb = pb->next;
				cur = cur->next;
			}
		}
		ps->next = bigger->next;
		pb->next = NULL;
		pHead = less->next;
		free(less);
		free(bigger);
		return pHead;
	}
};




//�������

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		// write code here
		if (A == NULL || A->next == NULL)
		{
			return true;
		}
		ListNode* slow, *fast, *cur, *next, *prev;
		slow = fast = A;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		cur = slow;
		prev = NULL;
		while (cur)
		{
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		while (prev)
		{
			if (A->val != prev->val)
			{
				return false;
			}
			prev = prev->next;
			A = A->next;
		}
		return true;
	}
};









//�ҵ������������ཻ����ʼ�ڵ㡣




/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	struct ListNode* curA = headA;
	struct ListNode* curB = headB;

	int lenA = 0;
	int lenB = 0;

	while (curA)
	{
		lenA++;
		curA = curA->next;
	}
	while (curB)
	{
		++lenB;
		curB = curB->next;
	}
	int value = abs(lenA - lenB);
	struct ListNode* longList = headA;
	struct ListNode* shortList = headB;
	if (lenA < lenB)
	{
		longList = headB;
		shortList = headA;
	}
	while (value--)
	{
		longList = longList->next;
	}
	while (longList && shortList)
	{
		if (longList == shortList)
		{
			return longList;
		}
		else
		{
			longList = longList->next;
			shortList = shortList->next;
		}
	}
	return NULL;
}






//�ж��Ƿ��л�


typedef struct ListNode Node; bool hasCycle(struct ListNode *head) {
	Node* slow = head;   
	Node* fast = head;

	while (fast && fast->next) 
	{
		slow = slow->next;      
		fast = fast->next->next;

		if (slow == fast)     
			return true;
	}

	return false;
}




//����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� NULL

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
typedef struct ListNode ListNode;
struct ListNode *detectCycle(struct ListNode *head) {
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			ListNode* meet = slow;
			ListNode* first = head;
			while (first != meet)
			{
				first = first->next;
				meet = meet->next;
			}
			return first;
		}
	}
	return NULL;
}




//����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㣬Ҫ�󷵻�����������ȿ�����




