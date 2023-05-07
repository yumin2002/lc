/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [971] Flip Binary Tree To Match Preorder Traversal
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
    vector<int> res;
    int index = 0;
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        return dfs(root, voyage) ? res : vector<int>{-1};
     }
    bool dfs(TreeNode* node, vector<int> & voyage) {
        if (!node) return true;
        if (node->val != voyage[index++]) return false;
        if (node->left && node->left->val != voyage[index]) {
            res.push_back(node->val);
            return dfs(node->right, voyage) && dfs(node->left, voyage);
        }
        return dfs(node->left, voyage) && dfs(node->right, voyage);
    }
};
// @lc code=end
// c++ reference PASS BY REFERENCE INSTEAD OF USING GLOBAL VARIABLES