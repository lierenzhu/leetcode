/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-04 17:15:05
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-04 17:25:42
 * @FilePath: /leetcode/leetcode-autumn/21.合并两个有序链表.cpp
 */
/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead=new ListNode();
        ListNode* cur=dummyHead;
        ListNode* cur1=list1;
        ListNode* cur2=list2;
        while(cur1!=nullptr&&cur2!=nullptr)
        {
            if(cur1->val<=cur2->val){
                cur->next=cur1;
                cur=cur->next;
                cur1=cur1->next;
            }else{
                cur->next=cur2;
                cur=cur->next;
                cur2=cur2->next;
            }
        }
        if(cur1==nullptr){
            cur->next=cur2;
        }
        if(cur2==nullptr){
            cur->next=cur1;
        }
        return dummyHead->next;
    }
};
// @lc code=end

