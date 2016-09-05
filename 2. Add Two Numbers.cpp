/*
https://leetcode.com/problems/add-two-numbers/
使用原来的节点，覆盖掉长节点的数据，节省空间
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
	ListNode* reverseNode(ListNode* l, int& len)//搞错了以为要反转，所以注释了反转代码
	{
		ListNode* reversel = NULL;
		for (ListNode * p = l; p != NULL;)
		{
			ListNode*pNext = p->next;//记录next指针因为下面操作会篡改p->next
			/*if(reversel == NULL)
			{
				p->next = NULL;
				reversel = p;
			}
			else
			{
				p->next = reversel;
				reversel = p;
			}*/
			len++;
			p = pNext;
		}
		//return reversel;
		return l;
	}
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int len1 = 0, len2 = 0;
		ListNode* reversel1 = reverseNode(l1, len1);
		ListNode* reversel2 = reverseNode(l2, len2);
		if(!reversel1)
		{
			return reversel2;
		}
		if (!reversel2)
		{
			return reversel1;
		}
		ListNode *p1 = reversel1, *p2 = reversel2;
		ListNode* ret = len1 > len2 ? p1 : p2;
		ListNode* p = ret;
		ListNode* pre = p;//记录前一个指针，为了最后一个进位使用
		int over;
		for(; p1 || p2;)
		{
			int val = 0;
			if(p1 && p2)//巧妙的将长度补齐，不够的就加0
			{
				val = p1->val + p2->val + over;
			}
			else
			{
			    if(!over)
			    {
			        return ret;
			    }
				val = p->val + over;
			}
			over = 0;
			if(val >= 10)
			{
				over = 1;
				p->val = val - 10;
			}
			else
			{
				p->val = val;
			}
			pre = p;
			p = p->next;
			if(p1)
			{
				p1 = p1->next;
			}
			if(p2)
			{
				p2= p2->next;
			}
		}
		if(over)//还有进位
		{
			pre->next = new ListNode(1);
		}
		return ret;
    }
};
