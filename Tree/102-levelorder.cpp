#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            vector<int> currentLevel; // 存储当前层的节点值
            //*第一个错误：应当直接用一个vector存储当前层的节点值，而不是想着用ans[i]来操作，会很麻烦 */
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                currentLevel.push_back(temp->val);
                //*第二个错误：如果为空节点，一定不要push，因为会报错，push空姐点也没有意义*/
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }

            ans.push_back(currentLevel);//important
        }

        return ans;
    }
};