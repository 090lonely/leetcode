//  void moveZeroes(vector<int>& nums) {
//         int n=nums.size();
//      for(auto it=nums.begin();it!=nums.end();it++){
//         if(*it==0){
//             nums.erase(it);
//             nums.push_back(0);
//         }
//      }
//     }
//您的代码中存在一个问题，导致它不能通过所有测试用例。问题在于您在遍历数组的同时删除元素并添加新元素。
//vector 的 erase 和 push_back 操作会改变容器的大小和元素的迭代器，这会导致未定义行为，因为您在遍历过程中修改了容器。
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
     int n=nums.size();int t=0;
     for(int i=0;i<n;i++){
        if(nums[i]!=0){
            nums[t]=nums[i];
            t++;
        }//直接遍历把非0的数搞到前面
     }
     for(int i=t;i<n;i++){
        nums[i]=0;
     }//添加0；
    }
};