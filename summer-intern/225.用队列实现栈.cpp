/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack
{
public:
    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
        top_num = x;
    }

    int pop()
    {
        int q_size = q1.empty() ? q2.size() : q1.size();
        if (q1.empty())
        {
            for (int i = 0; i < q_size - 1; ++i)
            {
                q1.push(q2.front());
                q2.pop();
            }
            top_num = q2.front();
            q2.pop();
        }
        else
        {
            for (int i = 0; i < q_size - 1; ++i)
            {
                q2.push(q1.front());
                q1.pop();
            }
            top_num = q1.front();
            q1.pop();
        }
        return top_num;
    }

    int top()
    {
        int q_size = q1.empty() ? q2.size() : q1.size();
        if (q1.empty())
        {
            for (int i = 0; i < q_size - 1; ++i)
            {
                q1.push(q2.front());
                q2.pop();
            }
            top_num = q2.front();
            q1.push(q2.front());
            q2.pop();
        }
        else
        {
            for (int i = 0; i < q_size - 1; ++i)
            {
                q2.push(q1.front());
                q1.pop();
            }
            top_num = q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        return top_num;
    }

    bool empty()
    {

        if (q1.empty() && q2.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    queue<int> q1, q2;
    int top_num;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
