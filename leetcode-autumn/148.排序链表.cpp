/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-12 21:55:08
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-12 22:15:37
 * @FilePath: \leetcode-autumn\148.排序链表.cpp
 */
/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        if(head==nullptr)
        {
            return nullptr;
        }
        priority_queue<int,vector<int>,greater<int>> pq;
        ListNode* dummyHead=new ListNode();
        dummyHead->next=head;
        ListNode* cur=head;
        while(cur!=nullptr)
        {
            pq.push(cur->val);
            cur=cur->next;
        }
        cur=dummyHead->next;
        while(!pq.empty())
        {
            cur->val=pq.top();
            pq.pop();
            cur=cur->next;
        }

        return dummyHead->next;

    }
};
// @lc code=end

