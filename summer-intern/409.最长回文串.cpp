/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> hash_map;
        for(char c:s)
        {
            hash_map[c]++;
        }

        int length=0;
        bool has_odd = false;

        for(unordered_map<char,int>::iterator it=hash_map.begin();it!=hash_map.end();++it)
        {
            if(it->second%2!=0)
            {
                has_odd = true;
            }

            length+=(it->second/2)*2;
        }

        if(has_odd)
        {
            return length+1;
        }
        else
        {
            return length;
        }

    }
};
// @lc code=end

