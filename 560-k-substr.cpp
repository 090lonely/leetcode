#include<bits/stdc++.h>
//********** */
using namespace std;
//使用哈希表的方法，具体解释见网址
//前缀和--连续子数组
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int count=0,pre=0;
        for(auto & x:nums){
            pre+=x;
            if(mp.find(pre-k)!=mp.end()){
                count+=mp[pre-k];
            }
            mp[pre]++;
        }
        return count;
    }
};
//网址也放到这里了，常回顾复习。
//https://leetcode.cn/problems/subarray-sum-equals-k/solutions/238572/he-wei-kde-zi-shu-zu-by-leetcode-solution/?envType=study-plan-v2&envId=top-100-liked