/*至上而下的递归合并方法*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* mergeOrderList(ListNode* left, int len1, ListNode* right, int len2){
		ListNode* ret = new ListNode(0);
		ListNode* p = ret;
		p->next = NULL;
		int i = 0, j = 0;
		while(i < len1 && j < len2)
		{
			if (left->val <= right->val)
			{
				p->next = left;
				left = left->next;
				++i;
			}
			else
			{
				p->next = right;
				right = right->next;
				++j;
			}
			p = p->next;
		}
		while( i < len1)
		{
			p->next = left;
			left = left->next;
			++i;
			p = p->next;
		}
		while( j < len2)
		{
			p->next = right;
			right = right->next;
			++j;
			p = p->next;
		}
		p->next = NULL;
		return ret->next;
	}
	ListNode* mergeSort(ListNode* p, int len){
		if(len == 0 || len == 1)
		{
			return p;
		}
		ListNode *p2 = p;
		int i = 0;
		while(i < len/2)
		{
			p2 = p2->next;
			++i;
		}
		ListNode *left = mergeSort(p, len/2);
		ListNode *right = mergeSort(p2, len - len/2);
		return mergeOrderList(left,len/2,right,len - len/2);
	}
	ListNode* sortList(ListNode* head) {
		if(!head || !head->next)
		{
			return head;
		}
		ListNode* p = head;
		int len = 0;
		while(p)
		{
			p = p->next;
			++len;
		}
		return mergeSort(head,len);
	}
};
/*至下而上的循环合并方法*/
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if(!head || !head->next)
		{
			return head;
		}
		ListNode* p = head;
		int len = 0;
		while(p)
		{
			p = p->next;
			++len;
		}
		ListNode* fakeNode = new ListNode(0);
		fakeNode->next = head;

		for(int step = 1; step < len; step <<= 1)
		{
			p = fakeNode->next;
			ListNode* tail = fakeNode;
			while(p)
			{
				ListNode* left = p;
				ListNode* right = split(left,step);
				p = split(right,step);
				tail = mergeOrderList(left,right,tail);
			}
		}
		return fakeNode->next;
	}
	ListNode* split(ListNode* p, int len){//get Next pointer
		for(int i = 1; p && i < len; ++i)
		{
			p = p->next;
		}
		if(!p)
		{
			return NULL;
		}
		ListNode *second = p->next;
		p->next = NULL;
		return second;
	}
	ListNode* mergeOrderList(ListNode* left, ListNode* right, ListNode* tail){
		while(left && right)
		{
			if(left->val <= right->val)
			{
				tail->next = left;
				left = left->next;
			}
			else
			{
				tail->next = right;
				right = right->next;
			}
			tail = tail->next;
		}
		tail->next = left ? left : right;
		while(tail->next)
		{
			tail = tail->next;
		}
		return tail;
	}
};
