/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool isBalance(TreeNode *root, int &depth) {
        if (root == NULL) {
            depth = 0;
            return true;
        }
        int leftDepth = 0, rightDepth = 0;
        bool balance = isBalance(root->left, leftDepth) && isBalance(root->right, rightDepth);
        depth = max(leftDepth, rightDepth) + 1;
        return balance && (abs(leftDepth - rightDepth) <= 1);
    }
public:
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return isBalance(root, depth);
    }
};
