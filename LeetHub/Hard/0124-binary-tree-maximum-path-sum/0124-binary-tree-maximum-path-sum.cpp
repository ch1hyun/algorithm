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
    int mx = -2000000000;
    int maxPathSum(TreeNode* root) {
        if (root->left != nullptr) {
            maxPathSum(root->left);
        }
        if (root->right != nullptr) {
            maxPathSum(root->right);
        }
        mx = max(mx, check(root));
        return mx;
    }

    int check(TreeNode* cur) {
        if (cur == nullptr) return -1001;
        int leftSum = check(cur->left);
        int rightSum = check(cur->right);

        return max(max(cur->val, max(leftSum + cur->val, rightSum + cur->val)), leftSum + rightSum + cur->val);
    }
};