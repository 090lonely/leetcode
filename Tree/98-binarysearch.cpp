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
  //验证一棵树是一颗二叉搜索树。递归利用上下界来检查是否符合。
class Solution {
public:
//设计一个函数，检测是否符合规范。
    bool helper(TreeNode*root,long long lower,long long upper){
        if(root==nullptr)return true;
        if(root->val <= lower||root->val>=upper)return false;
        return helper(root->left,lower,root->val)&&helper(root->right,root->val,upper);
    } 
    bool isValidBST(TreeNode* root) {
     return helper(root,LONG_MIN,LONG_MAX);
    }
};