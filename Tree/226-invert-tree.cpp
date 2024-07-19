#include<bits/stdc++.h>
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {//**** */
            return nullptr;
        }//空指针就返回空指针就行。
        TreeNode* left = invertTree(root->left);//关键是这里需要将递归的结果，也就是根节点接收
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};
