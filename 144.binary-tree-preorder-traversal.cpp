/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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


// Recursive: 
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> vec;
//         preOrder(root,vec);
//         return vec;
//     }
//     void preOrder(TreeNode* root, vector<int> & vec) {
//         if (root == nullptr) return;
//         vec.push_back(root->val);
//         preOrder(root->left, vec);
//         preOrder(root->right, vec);
//     }
// };

// Iterative
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> result;
//         if (root == nullptr) return result;
//         stack<TreeNode*> myStack;
//         myStack.push(root);
//         while (!myStack.empty()) {
//             TreeNode* curr = myStack.top();
//             myStack.pop();
//             if (curr != nullptr) {
//                 result.push_back(curr->val);
//                 myStack.push(curr->right);
//                 myStack.push(curr->left);
//             }
//         }
        
//         return result;
//     }
// };


// iterative 2
class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> res;
            stack<TreeNode*> Stack;
            TreeNode* curr = root;
            while (!Stack.empty() || curr != nullptr) {
                if (curr != nullptr) {
                    res.push_back(curr->val);
                    Stack.push(curr);
                    curr = curr->left;
                }
                else {
                    TreeNode* temp = Stack.top();
                    Stack.pop();
                    curr = temp->right;
                }
            }
            return res;
        }
};
// @lc code=end

// preorder is dfs
// Time complexity: O(n) visit each node once and perform constant time of work on each node
// space: O(n) spaec of the recursive call stack