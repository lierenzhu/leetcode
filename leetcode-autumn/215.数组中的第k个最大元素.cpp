/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-08-29 23:07:48
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-08-29 23:26:08
 * @FilePath: /leetcode-autumn/215.数组中的第k个最大元素.cpp
 */
/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

#include "bits/stdc++.h"

using namespace std;

// @lc code=start
void adjust(vector<int> &nums,int len,int index){
    int leftIdx=index*2+1;
    int rightIdx=index*2+2;
    int maxIdx=index;
    if(leftIdx<len&&nums[leftIdx]>nums[maxIdx]) maxIdx=leftIdx;
    if(rightIdx<len&&nums[rightIdx]>nums[maxIdx]) maxIdx=rightIdx;

    if(maxIdx!=index){
        swap(nums[index],nums[maxIdx]);
        adjust(nums,len,maxIdx);
    }

}
vector<int> heap_sort(vector<int> &nums){
    int length=nums.size();
    for(int i=(length-1)/2;i>=0;--i){
        adjust(nums,length,i);
    }
    for(int i=length-1;i>=1;--i){
        swap(nums[0],nums[i]);
        adjust(nums,i,0);
    }

    return nums;
}
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> sortedNums=heap_sort(nums);
        return sortedNums[nums.size()-k];

    }
};
// @lc code=end

