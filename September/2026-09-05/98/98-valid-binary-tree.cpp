// 98-valid-binary-tree.cpp;bt-recusion;help;leetcode

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
    bool checkBST(TreeNode* root, long long minValue, long long maxValue) {
        if (root == nullptr) {
            return true;
        }

        if (root->val <= minValue || root->val >= maxValue) {
            return false;
        }
        return checkBST(root->left, minValue, root->val) && checkBST(root->right, root->val, maxValue);
    }

    bool isValidBST(TreeNode* root) {
        return checkBST(root, LLONG_MIN, LLONG_MAX);
    }
};