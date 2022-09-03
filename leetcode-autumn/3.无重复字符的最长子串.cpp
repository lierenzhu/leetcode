/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-08-27 18:08:11
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-08-28 23:47:27
 * @FilePath: /leetcode-autumn/3.无重复字符的最长子串.cpp
 */
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 暴力
        // int length=s.length();
        // int result=0;
        // set<char> exists;
        // for(int i=0;i<length;++i){
        //     exists.clear();
        //     int temp=0;
        //     for(int j=i;j<length;++j){
        //         if(exists.count(s[j]))
        //         {
        //             break;
        //         }
        //         temp++;
        //         exists.insert(s[j]);
        //     }
        //     result=max(result,temp);
        // }
        // return result;

        // 滑动窗口
        int length=s.length();
        int maxLen=0;
        int left=0;
        unordered_set<char> exists;
        for(int i=0;i<length;++i)
        {
            while(exists.count(s[i]))
            {
                ++left;
                exists.erase(s[left]);
            }
            maxLen=max(maxLen,i-left+1);
            exists.insert(s[i]);
        }
        return maxLen;
    }
};
// @lc code=end

