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
bool check(TreeNode *p, TreeNode *q){
   if(!p&&!q)return true;
   if(!p||!q)return false;
   return p->val==q->val&&check(p->left,q->right)&&check(p->right,q->left);//当前节点相等&子节点对称
}
  bool isSymmetric(TreeNode* root) {
        return check(root, root);//起始时p，q均为root
    }
int main(){

}