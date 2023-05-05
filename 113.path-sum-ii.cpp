/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> curr;
        pathSum(root,targetSum, res,curr);
        return res;
    }
    void pathSum(TreeNode* root, int targetSum, vector<vector<int>> & res, vector<int> & curr) {
        if (!root) return;
        curr.push_back(root->val);
        if (!root->left && !root->right && targetSum == root->val) res.push_back(curr);
        pathSum(root->left, targetSum - root->val, res, curr);
        pathSum(root->right, targetSum - root->val, res, curr);
        curr.pop_back();
    }
};
// @lc code=end

