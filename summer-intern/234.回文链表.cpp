/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-14 20:01:37
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-14 20:48:40
 * @FilePath: /leetcode/234.回文链表.cpp
 */
/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next)
        {
            return true;
        }
        ListNode *fast_ptr=head, *slow_ptr=head;
        while(fast_ptr->next&&fast_ptr->next->next)
        {
            fast_ptr=fast_ptr->next->next;
            slow_ptr=slow_ptr->next;
        }

        slow_ptr->next=reverseList(slow_ptr->next);
        slow_ptr=slow_ptr->next;

        while(slow_ptr)
        {
            if(head->val!=slow_ptr->val)
            {
                return false;
            }
            head=head->next;
            slow_ptr=slow_ptr->next;
        }

        return true;

    }

    // ListNode* reverseList(ListNode *head)
    // {
    //     if(!head->next||!head)
    //     {
    //         return head;
    //     }
    //     ListNode *p=reverseList(head->next);
    //     head->next->next=head;
    //     head->next=nullptr;

    //     return p;
    // }

    ListNode* reverseList(ListNode *head)
    {
        ListNode *prev=nullptr,*next;
        while(head)
        {
            next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }

        return prev;
        
    }
};
// @lc code=end

