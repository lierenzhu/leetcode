/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-17 20:03:49
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-17 20:23:55
 * @FilePath: /leetcode/204.计数质数.cpp
 */
/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)
        {
            return 0;
        }
        vector<bool> prime(n,true);
        int count = n-2;
        for(int i=2;i*i<n;++i)
        {
            if(prime[i])
            {
                for(int j=i*i;j<n;j+=i)
                {
                    if(prime[j])
                    {
                        prime[j]=false;
                        count--;
                    }
                }
            }
        }
        return count;

    }
};
// @lc code=end

