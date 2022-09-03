/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2021-08-03 16:54:05
 * @LastEditors: lierenzhu
 * @LastEditTime: 2021-08-03 17:00:15
 * @FilePath: \leetcode\2.两数相加.cpp
 */
/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result = new ListNode(-1);
        ListNode *current = result;
        ListNode *last;
        int carry = 0;
        int temp = 0;
        for (; l1 != nullptr && l2 != nullptr; l1 = l1->next, l2 = l2->next)
        {
            temp = l1->val + l2->val + carry;
            if (temp >= 10)
            {
                carry = 1;
                current->val = temp - 10;
            }
            else
            {
                carry = 0;
                current->val = temp;
            }
            current->next = new ListNode();
            last = current;
            current = current->next;
        }
        //last->next=nullptr;
        //添加逻辑处理两个链表不等长的情况
        if (l1 != nullptr)
        {
            last->next = current;
            while (l1 != nullptr)
            {
                temp = carry + l1->val;
                if (temp >= 10)
                {
                    carry = 1;
                    current->val = temp - 10;
                }
                else
                {
                    carry = 0;
                    current->val = temp;
                }
                current->next = new ListNode();
                last = current;
                current = current->next;
                l1 = l1->next;
            }
        }
        else if (l2 != nullptr)
        {
            last->next = current;
            while (l2 != nullptr)
            {
                temp = carry + l2->val;
                if (temp >= 10)
                {
                    carry = 1;
                    current->val = temp - 10;
                }
                else
                {
                    carry = 0;
                    current->val = temp;
                }
                current->next = new ListNode();
                last = current;
                current = current->next;
                l2 = l2->next;
            }
        }
        if (carry == 1)
        {
            current->val = 1;
        }
        else
        {
            last->next = nullptr;
        }
        return result;
    }
};
// @lc code=end
