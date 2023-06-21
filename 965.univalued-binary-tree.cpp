/*
 * @lc app=leetcode id=965 lang=cpp
 *
 * [965] Univalued Binary Tree
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
// my recursion
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if (!root) return false;
        int val = root->val;
        return unival(root, val);
    }
    bool unival(TreeNode* root, int & val) {
        if (!root) return true;
        if (root->val != val) return false;
        return unival(root->left, val) && unival(root->right,val);
    }
};
// @lc code=end

// sample recursion
// class Solution {
//     public boolean isUnivalTree(TreeNode root) {
//         boolean left_correct = (root.left == null ||
//                 (root.val == root.left.val && isUnivalTree(root.left)));
//         boolean right_correct = (root.right == null ||
//                 (root.val == root.right.val && isUnivalTree(root.right)));
//         return left_correct && right_correct;
//     }
// }