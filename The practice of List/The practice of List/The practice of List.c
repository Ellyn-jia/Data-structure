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
//
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



//合并两个有序链表

// 创建一个新的带头单链表，每次取小的尾插

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



//以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/

//定义两个链表，一个存放小于x结点,一个存放大于等于x结点，最后再将两个链表链接在一起

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




//链表回文

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/

//定义快慢指针，找到中间元素，将中间元素之后的链表逆置后与前半部分比较

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









//找到两个单链表相交的起始节点。

//算出两个链表的长度差值，让长的链表的指针前走差值步，然后短的链表的指针和长的链表的指针一起走
//如果两指针相同则是起始结点

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






//判断是否有环
//定义快慢指针，如果有环，快指针一定能够追上慢指针

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




//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 NULL
//在快慢指针的相遇点的指针与链表开始的指针同步走，相遇点即为入环的第一个结点
//  起点到入环的长度 = N倍的环的周长 - 入环到相遇的长度

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




//给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点，要求返回这个链表的深度拷贝。
//先把copy的结点链接到原来结点的后面，在把随机指针拷贝一遍，最后把copy的指针拆下来

/*
// Definition for a Node.
class Node {
public:
int val;
Node* next;
Node* random;

Node(int _val) {
val = _val;
next = NULL;
random = NULL;
}
};
*/
class Solution {
public:
	Node* copyRandomList(Node* head) {
		Node* cur = head;
		while (cur)
		{
			Node* next = cur->next;
			Node* copy = (Node*)malloc(sizeof(Node));
			copy->val = cur->val;
			cur->next = copy;
			copy->next = next;
			cur = next;
		}
		cur = head;
		while (cur)
		{
			Node* copy = cur->next;
			if (cur->random != NULL)
			{
				copy->random = cur->random->next;
			}
			else
			{
				copy->random = NULL;
			}
			cur = copy->next;
		}
		Node* copyHead = NULL;
		Node* copyTail = NULL;
		cur = head;
		while (cur)
		{
			Node* copy = cur->next;
			Node* next = copy->next;
			if (copyTail == NULL)
			{
				copyHead = copyTail = copy;
			}
			else
			{
				copyTail->next = copy;
				copyTail = copy;
			}
			cur->next = next;
			cur = next;
		}
		return copyHead;

	}
};



