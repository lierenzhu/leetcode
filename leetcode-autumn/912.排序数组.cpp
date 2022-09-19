/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-09-04 15:22:35
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-19 12:41:47
 * @FilePath: \leetcode-autumn\912.排序数组.cpp
 */
/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class HeapSort {
public:
    void adjust(vector<int> &nums,int len,int index){
        int maxIndex=index;
        int leftIndex=index*2+1;
        int rightIndex=index*2+2;

        if(leftIndex<len&&nums[leftIndex]>nums[maxIndex]){
            maxIndex=leftIndex;
        }
        if(rightIndex<len&&nums[rightIndex]>nums[maxIndex]){
            maxIndex=rightIndex;
        }

        if(maxIndex!=index){
            swap(nums[maxIndex],nums[index]);
            adjust(nums,len,maxIndex);
        }

    }
    void heap_sort(vector<int> &nums){
        int len=nums.size();
        for(int i=(len-1)/2;i>=0;--i){
            adjust(nums,len,i);
        }
        for(int i=len-1;i>=1;--i){
            swap(nums[0],nums[i]);
            adjust(nums,i,0);
        }

    }
};
class Solution {
public:
    void quick_sort(vector<int> &nums,int leftIndex,int rightIndex){
        if(leftIndex<rightIndex){
            int randIndex=rand()%(rightIndex-leftIndex+1)+leftIndex;
            swap(nums[leftIndex],nums[randIndex]);
            int l=leftIndex,r=rightIndex,pivot=nums[leftIndex];
            while(l<r){
                while(l<r&&nums[r]>=pivot){
                    --r;
                }
                if(l<r){
                    nums[l++]=nums[r];
                }
                while(l<r&&nums[l]<=pivot){
                    ++l;
                }
                if(l<r){
                    nums[r--]=nums[l];
                }
            }
            nums[l]=pivot;
            quick_sort(nums,leftIndex,l-1);
            quick_sort(nums,l+1,rightIndex);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        // quick_sort(nums,0,nums.size()-1);
        HeapSort hpst;
        hpst.heap_sort(nums);
        return nums;
    }
};
// @lc code=end

