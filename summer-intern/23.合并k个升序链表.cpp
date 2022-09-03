/*
 * @Description:
 * @Author: lierenzhu
 * @Date: 2022-03-07 09:24:30
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-07 10:14:38
 * @FilePath: /leetcode/23.合并k个升序链表.cpp
 */
/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
class Solution
{
public:
    struct cmp
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        if (lists.empty())
        {
            return nullptr;
        }
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;

        for (ListNode *list : lists)
        {
            if (list)
            {
                pq.push(list);
            }
        }

        ListNode* ans = new ListNode(0), *cur = ans;
        while (!pq.empty())
        {
            cur->next = pq.top();
            pq.pop();
            cur = cur->next;
            if (cur->next)
            {
                pq.push(cur->next);
            }
        }

        return ans->next;
    }
};
// @lc code=end
