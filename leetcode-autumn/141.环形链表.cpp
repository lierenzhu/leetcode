/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-06 10:39:42
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-06 11:07:14
 * @FilePath: /leetcode/leetcode-autumn/141.环形链表.cpp
 */
/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        if(head==nullptr)
        {
            return false;
        }
        ListNode* fastPtr=head;
        ListNode* slowPtr=head;

        while(fastPtr->next!=nullptr)
        {
            fastPtr=fastPtr->next;
            if(fastPtr==slowPtr) return true;
            if(fastPtr->next!=nullptr)
            {
                fastPtr=fastPtr->next;
            }
            if(fastPtr==slowPtr) return true;
            slowPtr=slowPtr->next;
        }
        return false;
    }
};
// @lc code=end

