/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         trav(root, res);
//         return res;
//     }
//     void trav(TreeNode* root, vector<int> & res) {
//         if (root == nullptr) return;
//         trav(root->left, res);
//         res.push_back(root->val);
//         trav(root->right, res);
//     }
// };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> Stack;
        vector<int> result;
        TreeNode* curr = root;
        while (curr != nullptr || !Stack.empty()) {
            if (curr == nullptr) {
                TreeNode* node = Stack.top();
                result.push_back(node->val);
                Stack.pop();
                curr = node->right;
            }
            else {
                Stack.push(curr);
                curr = curr->left;
            }
        }
        return result;
    }
};
// @lc code=end

// stack:
// restu: 9 3 10  12 2 4 1 6 5 7

//             1
//         2     5
//       3  4   6 7
//      9  10 11
//          12