/*
https://leetcode.com/problems/reverse-linked-list/
思路：遍历链表，采用前插法。
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
    ListNode* reverseList(ListNode* head) {
        ListNode *ret = new ListNode(0);
        ListNode *p = ret;
        while(head)
        {
            ListNode* headNext = head->next;
            head->next = p->next;
            p->next = head;
            head = headNext;
        }
        return ret->next;
    }
};
 /*
 思路：采用递归法
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       if(!head || !head->next)
       {
           return head;
       }
       ListNode *node = reverseList(head->next);
       head->next->next = head;
       head->next = NULL;
       return node;
    }
};
