// 144-bt-preorder-traversal.cpp;bt;help;leeetcode

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        stack<TreeNode*> node;
        node.push(root);
        while(!node.empty()) {
            TreeNode* current = node.top();
            node.pop();
            result.push_back(current->val);
            if(current->right) {
                node.push(current->right);
            }
            if(current->left) {
                node.push(current->left);
            }
        }
        return result;
    }
};