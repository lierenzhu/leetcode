/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptrA = headA, *ptrB=headB;
        while(ptrA!=ptrB)
        {
            if(!ptrA)
            {
                ptrA=headB;
            }
            else
            {
                ptrA=ptrA->next;
            }
            if(!ptrB)
            {
                ptrB=headA;
            }
            else
            {
                ptrB=ptrB->next;
            }
        }
        return ptrA;
    }
};
// @lc code=end

