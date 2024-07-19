//bfs
//广度优先搜索--典型代表
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int min=0;int fresh=0;
        queue<pair<int,int>> q;
         for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) q.push({i, j});
        }
        //规定四个方向
        vector<pair<int,int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
        //bfs每一轮找到所有可以被转化的橙子，并且更新min和fresh
           while(!q.empty()) {
            //*** n */
            int n = q.size();//这里的n可以理解为每一轮腐蚀的源头的个数，类似于传染源的个数。
            bool rotten = false;//记录每一轮腐蚀是否有橘子变坏，记录全部腐烂的时间。
            for(int i = 0; i < n; i++) {
                auto x = q.front();
                q.pop();
                for(auto cur: dirs) {
                    int i = x.first + cur.first;
                    int j = x.second + cur.second;
                    if(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1) {
                        grid[i][j] = 2;
                        q.push({i, j});
                        fresh--;
                        rotten = true;
                    }
                }
            }
            if(rotten) min++;//一轮腐蚀完成。
        } 
        return fresh ? -1 : min;
    }
};