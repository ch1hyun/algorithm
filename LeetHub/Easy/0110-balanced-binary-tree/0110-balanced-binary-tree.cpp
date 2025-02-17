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
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        bool ret = isBalanced(root->left) && isBalanced(root->right);
        
        return ret && abs(getMaximumDepth(root->left) - getMaximumDepth(root->right)) <= 1;
    }

    int getMaximumDepth(TreeNode* cur, int depth = 1) {
        if (cur == NULL) return depth - 1;
        return max(getMaximumDepth(cur->left, depth + 1), getMaximumDepth(cur->right, depth + 1));
    }
};