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
        return mx = max(mx, check(root, root));
    }

    int check(TreeNode* cur, TreeNode* entryNode) {
        if (cur == nullptr) return -1001;
        int leftSum = check(cur->left, entryNode);
        int rightSum = check(cur->right, entryNode);

        int ret = max(cur->val, max(leftSum + cur->val, rightSum + cur->val));

        if (cur == entryNode) {
            return max(ret, leftSum + rightSum + cur->val);
        }

        return ret;
    }
};