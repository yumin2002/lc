/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

// @lc code=start
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
// class Solution {
// public:
//     bool isBalanced(TreeNode* root) {
//         if (!root) return;
//         int l = maxDepth(root->left);
//         int r = maxDepth(root->right);
//         if ((abs(l-r)) > 1) return false;
//         return isBalanced(root->left) && isBalanced(root->right);
//     }

//     int maxDepth(TreeNode* root) {
//         if (!root) return 0;
//         int l = maxDepth(root->left);
//         int r = maxDepth(root->right);
//         return max(l, r) + 1;
//     }
// };

// only one recursive function:
class Solution {
public: 
    bool isBalanced(TreeNode* root) {
        if (!root) return;
        bool balanced = true;
        maxDepth(root, balanced);
        return balanced;
    }
    int maxDepth(TreeNode* root, bool balanced) {
        if (!root) return 0;
        l = maxDepth(root->left);
        r = maxDepth(root->right);
        if (abs(l-r) > 1) {
            balanced = false;
            return -1;
        }
        return max(l, r) + 1;
    }
};
// @lc code=end

