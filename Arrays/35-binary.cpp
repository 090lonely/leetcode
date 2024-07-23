#include<bits/stdc++.h>
//********** */
using namespace std;
//最简单而且最重要的二分查找
//注意题目要求。
//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//请必须使用时间复杂度为 O(log n) 的算法。
class Solution {
public://校招字节一面
    int searchInsert(vector<int>& nums, int target) {
        int n= nums.size();
        int left=0,right=n-1,ans=n;
        while(left<=right){
            int mid=(right+left)>>1;
            if(target>nums[mid]){
               left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return left;
    }
};