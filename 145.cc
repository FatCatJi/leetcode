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
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodeStack;
        stack<bool> visitStack;
        TreeNode *node = root;
        while (node != nullptr || !nodeStack.empty()) {
            while (node != NULL) {
                nodeStack.push(node);
                visitStack.push(false);
                node = node->left;
            }
            if (visitStack.top()) {
                result.push_back(nodeStack.top()->val);
                nodeStack.pop();
                node = nullptr;
                visitStack.pop();
            } else {
                node = nodeStack.top()->right;
                visitStack.top() = true;
            }
        };
        return result;
    }
};
