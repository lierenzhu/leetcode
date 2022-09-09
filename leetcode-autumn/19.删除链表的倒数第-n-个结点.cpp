/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-09 17:23:29
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-09 17:40:01
 * @FilePath: /leetcode/leetcode-autumn/19.删除链表的倒数第-n-个结点.cpp
 */
/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyHead=new ListNode();
        dummyHead->next=head;
        ListNode* slow=dummyHead;
        ListNode* fast=head;
        for(int i=0;i<n;++i)
        {
            fast=fast->next;
        }
        while(fast!=nullptr)
        {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;

        return dummyHead->next;
    }
};
// @lc code=end

