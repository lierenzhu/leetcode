/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-14 21:24:48
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-14 22:03:45
 * @FilePath: /leetcode/83.删除排序链表中的重复元素.cpp
 */
/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
        {
            return head;
        }
        ListNode *prev=head, *cur=head->next;
        while(cur)
        {
            if(prev->val==cur->val)
            {
                prev->next=cur->next;
                delete cur;
                cur=prev->next;
            }
            else
            {
                prev=cur;
                cur=cur->next;
            }
        }

        return head;

    }
};
// @lc code=end

