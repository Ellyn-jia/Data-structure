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






//�������������ҳ����ǵĵ�һ���������

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	int lenA = 0, lenB = 0;    
	struct ListNode* curA = headA, *curB = headB;    
	//����������   
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
	//�ó��������߼���   
	while(gap--)
	{      
		longList = longList->next;  
	}    //��������ͬʱ�ߣ�ֱ��������ͬ�Ľڵ�   
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


//�����������

typedef struct ListNode Node; struct ListNode* insertionSortList(struct ListNode* head){
	if (head == NULL || head->next == NULL)
		return head;
	//������������   
	Node* sortHead = (Node*)malloc(sizeof(Node));
	//ͷ�ڵ����Ȳ���   
	sortHead->next = head;
	head = head->next;
	sortHead->next->next = NULL;
	//����ʣ��ڵ� 
	Node* cur = head;
	while (cur)
	{
		//���ȱ���next�ڵ�    
		Node* next = cur->next;
		// �����������ͷ��ʼ����������Ľڵ��ҵ�һ�����ʵ�λ��       
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
		//�ں���λ�ý��в���    
		sortPrev->next = cur;
		cur->next = sortCur;
		cur = next;
	}

	Node* sortList = sortHead->next;
	free(sortHead);

	return sortList;
}




//ɾ���ظ��ڵ�

class Solution {
public:    ListNode* deleteDuplication(ListNode* pHead)    {
			   if (pHead == NULL || pHead->next == NULL)    
				   return pHead;           
			   struct ListNode* n0 = NULL;
			   struct ListNode* n1 = pHead;        
			   struct ListNode* n2 = n1->next;   
			   while (n2 != NULL)     
			   {         
				   //������ڽڵ㲻��ͬ������Ҫɾ�������½ڵ㣬����������        
				   if(n1->val != n2->val)      
				   {              
					   n0 = n1;   
					   n1 = n2;     
					   n2 = n2->next;       
				   }         
				   else      
				   {        
					   //������ڽڵ���ͬ      
					   //��n2ȥ�ҵ�һ������ͬ�Ľڵ�  
					   while(n2 && n2->val == n1->val)   
					   {                
						   n2 = n2->next;           
					   }           
					   //�������ӣ����Ҫɾ���İ���ͷ�ڵ㣬�����ͷ�ڵ�      
					   if(n0)                 
						   n0->next = n2;           
					   else                 
						   pHead = n2;      
					   // ɾ�����ظ��Ľڵ�  
					   while(n1 != n2)      
					   {                  
						   struct ListNode* next = n1->next;     
						   free(n1);                  
						   n1 = next;             
					   }             
					   //���½ڵ�      
					   n1 = n2;        
					   if(n2)           
						   n2 = n2->next; 
				   }    
			   }           
			   return pHead; 
}
};




//


class Solution {
public:    Node* copyRandomList(Node* head) {       
			   // 1.�������������뵽ԭ�ڵ�ĺ���    
			   Node* cur = head;      
			   while(cur)      
			   {         
				   Node* next = cur->next;

			   
				   Node* copy = (Node*)malloc(sizeof(Node));        
				   copy->val = cur->val;

	           
				   cur->next = copy;            
				   copy->next = next;

				   cur = next;      
			   }

			   cur = head;      
			   while(cur)      
			   {         
				   Node* copy = cur->next;  
				   if(cur->random != NULL)
					   copy->random = cur->random->next;
				   else                
					   copy->random = NULL;
				   cur =copy->next;
			   }

			   Node* copyHead = NULL, *copyTail = NULL;       
			   cur = head;      
			   while(cur)     
			   {          
				   Node* copy = cur->next;   
				   Node* next = copy->next;

				   if(copyTail == NULL)       
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
} };



