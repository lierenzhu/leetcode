/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-14 09:43:28
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-14 10:17:16
 * @FilePath: /leetcode/leetcode-autumn/2.两数相加.cpp
 */
/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead=new ListNode();
        ListNode* cur1=l1;
        ListNode* cur2=l2;
        ListNode* cur=dummyHead;
        int carry=0;

        while(cur1!=nullptr&&cur2!=nullptr)
        {
            int sum=cur1->val+cur2->val+carry;
            if(sum>=10)
            {
                carry=1;
                sum%=10;
            }else{
                carry=0;
            }
            cur->next=new ListNode(sum);
            cur=cur->next;
            cur1=cur1->next;
            cur2=cur2->next;
        }
        while(cur1!=nullptr)
        {
            int sum=cur1->val+carry;
            if(sum>=10)
            {
                carry=1;
                sum%=10;
            }else{
                carry=0;
            }
            cur->next=new ListNode(sum);
            cur=cur->next;
            cur1=cur1->next;
        }
        while(cur2!=nullptr)
        {
            int sum=cur2->val+carry;
            if(sum>=10)
            {
                carry=1;
                sum%=10;
            }else{
                carry=0;
            }
            cur->next=new ListNode(sum);
            cur=cur->next;
            cur2=cur2->next;
        }
        if(carry==1)
        {
            cur->next=new ListNode(1);
        }
        return dummyHead->next;


    }
};
// @lc code=end

