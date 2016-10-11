/*
想法一：先记录第m-1个结点指针p，然后m-n的数据反转，再将记录的该节点p->next = 第n个结点的next。
*/
	class Solution {
	public:
		ListNode* reverseBetween(ListNode* head, int m, int n) {
			if(m == n)
				return head;
			ListNode* fakeNode = new ListNode(0);
			fakeNode->next = head;
			ListNode* slow = fakeNode, *fast = fakeNode;
			for(int i = 1; i < m; ++i)
			{
				slow = fast = fast->next;
			}
			fast = fast->next;
			ListNode* startNode = fast;
			for(int j = m; j <= n; ++j)
			{
				ListNode* saveFast = fast->next;
				fast->next = slow->next;
				slow->next = fast;
				fast = saveFast;
			}
			startNode->next = fast;
			return fakeNode->next;
		}
	};
  
 /*
 想法二：边遍历边翻转，不需要另外处理最后不翻转部分的连接问题。若有n1->n2->n3->n4->... 每次都形如n1->n3->n2->n4。
 可用伪（头）结点或者指针的指针来避免第一个结点需要另外处理的问题。
 */
 	class Solution {
	public:
		ListNode* reverseBetween(ListNode* head, int m, int n) {
			ListNode* fakeNode = new ListNode(0);
			fakeNode->next = head;
			ListNode* slow = fakeNode;
			for(int i = 1; i < m; ++i)
			{
				slow = slow->next;
			}
			ListNode* fast = slow->next;
			for(int i = m; i < n; ++i)
			{
				swap(slow->next,fast->next->next);
				swap(slow->next,fast->next);
			}
			return fakeNode->next;
		}
	};
  
////////////////
	class Solution {
	public:
		ListNode* reverseBetween(ListNode* head, int m, int n) {
			ListNode** pre = &head;
			for(int i = 1; i < m; ++i)
			{
				pre = &(*pre)->next;
			}
			ListNode** fast = &(*pre)->next;
			for(int i = m; i < n; ++i)
			{
				swap((*pre),(*fast)->next);
				swap((*pre),(*fast));
			}
			return head;
		}
	};
  
