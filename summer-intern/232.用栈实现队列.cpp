/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-06 14:01:43
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-06 14:16:48
 * @FilePath: /leetcode/232.用栈实现队列.cpp
 */
/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        while(!temp_stack.empty())
        {
            main_stack.push(temp_stack.top());
            temp_stack.pop();
        }

        main_stack.push(x);

    }
    
    int pop() {
        while(!main_stack.empty())
        {
            temp_stack.push(main_stack.top());
            main_stack.pop();
        }

        int x=temp_stack.top();
        temp_stack.pop();

        return x;

    }
    
    int peek() {
        while(!main_stack.empty())
        {
            temp_stack.push(main_stack.top());
            main_stack.pop();
        }

        return temp_stack.top();

    }
    
    bool empty() {

        if(main_stack.empty()&&temp_stack.empty())
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    stack<int> main_stack;
    stack<int> temp_stack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

