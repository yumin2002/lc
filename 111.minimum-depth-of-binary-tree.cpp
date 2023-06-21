/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        if (root->left && root->right) return min(minDepth(root->left), minDepth(root->right)) + 1;
        if (root->left) return minDepth(root->left) + 1;
        if (root->right) return minDepth(root->right) + 1;
        return 0;
    }
};
// @lc code=end


// some sample solution:
// class Solution {
// public:
//   int minDepth(TreeNode* root) {
//     if (!root) return 0;
//     if (!root->left && !root->right) return 1;
//     int l = root->left ? minDepth(root->left) : INT_MAX;
//     int r = root->right ? minDepth(root->right) : INT_MAX;
//     return min(l, r) + 1;
//   }
// };

