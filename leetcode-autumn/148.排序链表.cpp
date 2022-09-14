/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-12 21:55:08
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-13 10:38:20
 * @FilePath: /leetcode/leetcode-autumn/148.排序链表.cpp
 */
/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        return sortList(head,nullptr);
    }
    ListNode* sortList(ListNode *head, ListNode* tail){
        if(head==nullptr)
        {
            return head;
        }
        if(head->next==tail)
        {
            head->next=nullptr;
            return head;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=tail)
        {
            slow=slow->next;
            fast=fast->next;
            if(fast!=tail)
            {
                fast=fast->next;
            }
        }
        ListNode* mid=slow;

        return merge(sortList(head,mid),sortList(mid,tail));

    }
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* cur1=head1;
        ListNode* cur2=head2;
        ListNode* dummyHead=new ListNode();
        ListNode* cur=dummyHead;

        while(cur1!=nullptr&&cur2!=nullptr)
        {
            if(cur1->val<=cur2->val)
            {
                cur->next=cur1;
                cur1=cur1->next;
            }else{
                cur->next=cur2;
                cur2=cur2->next;
            }
            cur=cur->next;
        }

        if(cur1!=nullptr)
        {
            cur->next=cur1;
        }else if(cur2!=nullptr)
        {
            cur->next=cur2;
        }

        return dummyHead->next;

    }
};
// @lc code=end

