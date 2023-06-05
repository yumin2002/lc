/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
// recursive
// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         return isMirror(first, second);
//     }

//     bool isMirror(TreeNode* first, TreeNode* second) {
//         if (!first && !second) return true;
//         if (!first || !second) return false;
//         if (first->val != second->val) return false;
//         return isMirror(first->left, second->right) && isMirror(first->right, second->left);
//     }
// };

// iterative
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            TreeNode* t1 = q.front();
            q.pop();
            TreeNode* t2 = q.front();
            q.pop();
            if (t1 == nullptr && t2 == nullptr) continue;
            if (!t1 || !t2) return false;
            if (t1->val != t2->val) return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }        
};

// @lc code=end

