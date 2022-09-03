/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-17 20:26:16
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-17 20:40:41
 * @FilePath: /leetcode/504.七进制数.cpp
 */
/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        string ans;
        if(num==0)
        {
            return "0";
        }
        bool is_negative=false;
        if(num<0)
        {
            is_negative=true;
            num=abs(num);
        }

        while(num)
        {
            int a=num/7,b=num%7;
            ans=to_string(b)+ans;
            num=a;
        }

        if(is_negative)
        {
            ans='-'+ans;
        }

        return ans;



    }
};
// @lc code=end

