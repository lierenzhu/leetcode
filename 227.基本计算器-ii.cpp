/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-13 19:48:56
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-13 21:06:25
 * @FilePath: /leetcode/227.基本计算器-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution {
public:
        stack<char> ops;
        stack<int> nums;

    void cal()
    {
        int a=nums.top();
        nums.pop();
        int b=nums.top();
        nums.pop();
        char op=ops.top();
        ops.pop();


        int result=0;

        switch(op)
        {
            case '+':
            result=b+a;
            break;
            case '-':
            result=b-a;
            break;
            case '*':
            result=b*a;
            break;
            case '/':
            result=b/a;
            break;
        }


        nums.push(result);
    }

    int calculate(string s) {

        unordered_map<char,int> pri;
        pri['+']=2;
        pri['-']=2;
        pri['*']=1;
        pri['/']=1;

        s='0'+s;

        for(int i=0;i<s.length();++i)
        {
            if(s[i]==' ')
            {
                continue;
            }
            string temp="";
            if(isdigit(s[i]))
            {
                while(isdigit(s[i]))
                {
                    temp+=s[i];
                    i++;
                }
                nums.push(stoi(temp));
                --i;
            }
            else
            {
                while(!ops.empty()&&pri[ops.top()]<=pri[s[i]])
                {
                    cal();
                }
                ops.push(s[i]);
            }
        }

        while(!ops.empty())
        {
            cal();
        }

        return nums.top();

    }
};
// @lc code=end

