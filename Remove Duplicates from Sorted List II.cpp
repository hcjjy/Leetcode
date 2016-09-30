/*
思路1:遍历链表看前面一个结点是否是重复结点,如果不是就选择前面那个结点，否则不选择。
*/
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
    ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next)
		{
			return head;
		}
        ListNode* ret = new ListNode(0);
		ret->next =head;
		ListNode* pre = ret;
		ListNode* p = head;
		ListNode* prepre = pre;
	    int val = p->val;
		pre = p;
		p = p->next;
		bool preOnly = true;
		while(p)
		{
			if(p->val == val)
			{
				preOnly = false;
			}
			else
			{
				val = p->val;
				if(preOnly)
				{
					prepre->next = pre;
					prepre = pre;
				}
				else
				{
					preOnly = true;
				}
				pre = p;
			}
			p = p->next;
		}
		if(preOnly)
		{
		    prepre->next = pre;
		    prepre = pre;
		}
		prepre->next = NULL;
		return ret->next;
    }
};

/*思路清晰的解决方法*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next)
		{
			return head;
		}
        ListNode* ret = new ListNode(0);
		ret->next =head;
		ListNode* pre = ret;
		ListNode* p = head;
		while(p)
		{
			if(p->next && p->next->val == p->val)
			{
			    ListNode * tmp = p->next;
			    while(tmp && tmp->val == p->val)
			    {
			        tmp = tmp->next;
			    }
			    p = tmp;
			    pre->next = p;
			}
			else
			{
			    pre = p;
			    p = p->next;
			}
		}
		return ret->next;
    }
};

/*方法三没有伪结点，用指针的指针*/
class Solution {
 public:
	 ListNode* deleteDuplicates(ListNode* head) {
		 if (!(head && head->next))
		 {
			 return head;
		 }
		 ListNode** pre = &head;
		 while(*pre)
		 {
			 if((*pre)->next && (*pre)->next->val == (*pre)->val)
			 {
				 ListNode* tmp = (*pre)->next;
				 while(tmp && tmp->val == (*pre)->val)
				 {
					 tmp = tmp->next;
				 }	
				 *pre = tmp;
			 }
			 else
			 {
				 pre= &((*pre)->next);
			 }
		 }
		 return head;
	 }
 };
