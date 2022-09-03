/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-04 15:18:29
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-04 15:53:17
 * @FilePath: /leetcode/769.最多能完成排序的块.cpp
 */
/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 */

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        int cut=0;
        int max_num=-1;

        //如果arr[i]之前元素的最大值与下标相等，说明这个子数组中包含的元素可以有序排列而不影响总的数组顺序，所以可以在这里做一次分割
        for(int i=0;i<arr.size();++i)
        {
            if(arr[i]>max_num)
            {
                max_num=arr[i];
            }
            if(i==max_num)
            {
                cut++;
            }
        }

        return cut;

    }
};
// @lc code=end

