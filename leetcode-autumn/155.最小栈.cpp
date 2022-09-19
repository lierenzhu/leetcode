/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-19 10:22:47
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-19 10:33:43
 * @FilePath: /leetcode/leetcode-autumn/155.最小栈.cpp
 */
/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include "bits/stdc++.h"
using namespace std;

// @lc code=start
class MinStack
{
public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (min_stack.empty() || val <= min_stack.top())
        {
            min_stack.push(val);
        }
        main_stack.push(val);
    }

    void pop()
    {
        if (min_stack.top() == main_stack.top())
        {
            min_stack.pop();
        }
        main_stack.pop();
    }

    int top()
    {
        return main_stack.top();
    }

    int getMin()
    {
        return min_stack.top();
    }

private:
    stack<int> main_stack, min_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
