/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-03 14:55:08
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-03 15:16:06
 * @FilePath: /leetcode/241.为运算表达式设计优先级.cpp
 */
/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {

        vector<int> ways;
        for(int i=0;i<expression.length();++i)
        {
            char c=expression[i];
            if(c=='+'||c=='-'||c=='*')
            {
                vector<int> left=diffWaysToCompute(expression.substr(0,i));
                vector<int> right=diffWaysToCompute(expression.substr(i+1));
                for(const int & i:left)
                {
                    for(const int & j:right)
                    {
                        switch(c)
                        {
                            case '+':
                            ways.push_back(i+j);
                            break;
                            case '-':
                            ways.push_back(i-j);
                            break;
                            case '*':
                            ways.push_back(i*j);
                            break;
                        }
                    }
                }
            }
        }
        if(ways.empty())
        {
            ways.push_back(stoi(expression));
        }

        return ways;

    }
};
// @lc code=end

