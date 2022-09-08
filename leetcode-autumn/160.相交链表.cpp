/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-08 10:13:33
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-08 10:42:25
 * @FilePath: /leetcode/leetcode-autumn/160.相交链表.cpp
 */
/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *nodeA=headA;
        ListNode *nodeB=headB;

        while(nodeA!=nodeB)
        {
            if(nodeA==nullptr)
            {
                nodeA=headB;
            }else{
                nodeA=nodeA->next;
            }
            if(nodeB==nullptr)
            {
                nodeB=headA;
            }else{
                nodeB=nodeB->next;
            }
        }
        return nodeA;
    }
};
// @lc code=end

