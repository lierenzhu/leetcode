/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-21 10:11:30
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-21 10:33:17
 * @FilePath: /leetcode/leetcode-autumn/234.回文链表.cpp
 */
/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */
#include "bits/stdc++.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next!=nullptr&&fast->next->next!=nullptr)
        {
            fast=fast->next->next;
            slow=slow->next;
        }

        slow=reverseList(slow->next);

        while(slow!=nullptr)
        {
            if(slow->val!=head->val)
            {
                return false;
            }
            slow=slow->next;
            head=head->next;
        }

        return true;

    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev=nullptr;
        while(head!=nullptr)
        {
            ListNode* next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }

        return prev;
    }
};
// @lc code=end

