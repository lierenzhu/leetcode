/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-14 11:16:05
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-14 11:37:10
 * @FilePath: /leetcode/21.合并两个有序链表.cpp
 */
/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result= new ListNode(0);
        ListNode* ptr=result;
        while(list1&&list2)
        {
            if(list2->val<=list1->val)
            {
                ptr->next=list2;
                list2=list2->next;
            }
            else
            {
                ptr->next=list1;
                list1=list1->next;
            }
                ptr=ptr->next;
        }
        ptr->next=list1?list1:list2;

        return result->next;
    }
};
// @lc code=end

