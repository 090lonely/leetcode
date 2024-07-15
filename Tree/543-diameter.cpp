#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
int max1;
    int depth(TreeNode* rt){
if(rt==nullptr){return 0;}
int l,r;
l=depth(rt->left);r=depth(rt->right);
if(l+r>max1){max1=l+r;}//每计算一次左右高度和，就与max进行比较and更新
return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        max1=0;
        depth(root);
        return max1;
    }
};