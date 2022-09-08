/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-08 11:19:15
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-08 11:44:36
 * @FilePath: /leetcode/leetcode-autumn/142.环形链表-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */
#include "bits/stdc++.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast!=nullptr)
        {
            if(fast->next==nullptr)
            {
                return nullptr;
            }
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
            {
                fast=head;
                while(fast!=slow)
                {
                    fast=fast->next;
                    slow=slow->next;
                }
                return fast;
            }
        }
        
        return nullptr;
    }
};
// @lc code=end

