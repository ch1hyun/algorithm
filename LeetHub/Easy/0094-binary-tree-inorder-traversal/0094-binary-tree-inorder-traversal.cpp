/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;

        solve(ret, root);

        return ret;
    }

    void solve(vector<int> &ret, TreeNode* cur) {
        if (cur == NULL) return;

        solve(ret, cur->left);
        ret.push_back(cur->val);
        solve(ret, cur->right);
    }
};