/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-14 10:40:17
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-14 20:32:51
 * @FilePath: /leetcode/206.反转链表.cpp
 */
/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {

//非递归
        // ListNode *pre=nullptr, *next;
        // while(head)
        // {
        //     next=head->next;
        //     head->next=pre;
        //     pre=head;
        //     head=next;
        // }

        // return pre;

//递归
        if(!head||!head->next)
        {
            return head;
        }
        ListNode* p=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;

        return p;

    }

};
// @lc code=end

