/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-14 14:39:59
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-14 15:14:20
 * @FilePath: /leetcode/24.两两交换链表中的节点.cpp
 */
/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *result=new ListNode(0);
        result->next = head;
        ListNode *prev=result;
        while(prev->next&&prev->next->next)
        {
            ListNode *cur=prev->next;
            ListNode *next=prev->next->next;

            prev->next=next;
            cur->next=next->next;
            next->next=cur;

            prev=cur;
        }

        return result->next;

    }
};
// @lc code=end

