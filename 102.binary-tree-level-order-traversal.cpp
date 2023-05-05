/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> myQueue;
        vector<vector<int>> res;
        myQueue.push(root);
        if(root == nullptr)return res ;
        while (!myQueue.empty()) {
            vector<int> currLevel;
            int curr_size = myQueue.size();
            while (curr_size--) {
                TreeNode* curr = myQueue.front();
                myQueue.pop();
                if (curr->left) {
                    myQueue.push(curr->left);
                }
                if (curr->right) {
                    myQueue.push(curr->right);
                }
                currLevel.push_back(curr->val);
            }
            if (curr_size) {
                res.push_back(currLevel);
            }
        }
        return res;
    }
};
// @lc code=end

