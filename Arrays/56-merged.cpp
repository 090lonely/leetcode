#include<bits/stdc++.h>
//********** */
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 我们用数组 merged 存储最终的答案。

// 首先，我们将列表中的区间按照左端点升序排序。然后我们将第一个区间加入 merged 数组中，并按顺序依次考虑之后的每个区间：
 if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merged;
        for(int i=0;i<intervals.size();i++){
            int l=intervals[i][0],r=intervals[i][1];
            if(!merged.size()||l>merged.back()[1])merged.push_back({l,r});
            // 如果当前区间的左端点在数组 merged 中最后一个区间的右端点之后，那么它们不会重合，我们可以
//直接将这个区间加入数组 merged 的末尾；
            else{merged.back()[1]=max(merged.back()[1],r);}
            // 否则，它们重合，我们需要用当前区间的右端点更新数组 merged 中最后一个区间的右端点，将其置为二者的较大值。

        }
        return merged;
    }
};
