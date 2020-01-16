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



//链表分割


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



//链表回文

class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		// write code here

		if (A == NULL || A->next == NULL)
			return true;      
		ListNode* slow, *fast, *prev, *cur, *nxt;        
		slow = fast = A;        
		//找到中间节点        
		while (fast && fast->next)
		{            
			slow = slow->next;            
			fast = fast->next->next;        
		}        prev = NULL;        
		//后半部分逆置        
		cur = slow;       
		while (cur)       
		{           
			next = cur->next;            
			cur->next = prev;            
			prev = cur;            
			cur = nxt;        
		}       
		//逐点比对        
		while (A && prev)       
		{            
			if (A->val != prev->val)           
				return false;       
			A = A->next;         
			prev = prev->next;   
		} 
	}
};







struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	int lenA = 0, lenB = 0;    
	struct ListNode* curA = headA, *curB = headB;    
	//计算链表长度   
	while(curA)
	{      
		++lenA;    
		curA = curA->next;   
	}       
	while(curB)
	{ 
		++lenB;     
		curB = curB->next;
	}       
	int gap = abs(lenA - lenB);    
	struct ListNode* longList = headA, *shortList = headB;   
	if (lenA < lenB) { longList = headB;      
	shortList = headA; }   
	//让长链表先走几步   
	while(gap--)
	{      
		longList = longList->next;  
	}    //两个链表同时走，直到遇到相同的节点   
	while(longList && shortList)  
	{      
		if(longList->val == shortList->val)
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


//链表插入排序

typedef struct ListNode Node; struct ListNode* insertionSortList(struct ListNode* head){
	if (head == NULL || head->next == NULL)
		return head;
	//创建排序链表   
	Node* sortHead = (Node*)malloc(sizeof(Node));
	//头节点首先插入   
	sortHead->next = head;
	head = head->next;
	sortHead->next->next = NULL;
	//插入剩余节点 
	Node* cur = head;
	while (cur)
	{
		//首先保存next节点    
		Node* next = cur->next;
		// 从排序链表的头开始，给待插入的节点找到一个合适的位置       
		Node* sortPrev = sortHead;
		Node* sortCur = sortHead->next;
		while (sortCur)
		{
			if (cur->val > sortCur->val)
			{
				sortPrev = sortCur;
				sortCur = sortCur->next;
			}
			else
			{
				break;
			}
		}
		//在合适位置进行插入    
		sortPrev->next = cur;
		cur->next = sortCur;
		cur = next;
	}

	Node* sortList = sortHead->next;
	free(sortHead);

	return sortList;
}




//删除重复节点

class Solution {
public:    ListNode* deleteDuplication(ListNode* pHead)    {
			   if (pHead == NULL || pHead->next == NULL)    
				   return pHead;           
			   struct ListNode* n0 = NULL;
			   struct ListNode* n1 = pHead;        
			   struct ListNode* n2 = n1->next;   
			   while (n2 != NULL)     
			   {         
				   //如果相邻节点不相同，则不需要删除，更新节点，继续向后遍历        
				   if(n1->val != n2->val)      
				   {              
					   n0 = n1;   
					   n1 = n2;     
					   n2 = n2->next;       
				   }         
				   else      
				   {        
					   //如果相邻节点相同      
					   //则n2去找第一个不相同的节点  
					   while(n2 && n2->val == n1->val)   
					   {                
						   n2 = n2->next;           
					   }           
					   //重新链接，如果要删除的包括头节点，则更新头节点      
					   if(n0)                 
						   n0->next = n2;           
					   else                 
						   pHead = n2;      
					   // 删除掉重复的节点  
					   while(n1 != n2)      
					   {                  
						   struct ListNode* next = n1->next;     
						   free(n1);                  
						   n1 = next;             
					   }             
					   //更新节点      
					   n1 = n2;        
					   if(n2)           
						   n2 = n2->next; 
				   }    
			   }           
			   return pHead; 
}
};
