/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> result;
//         if (root== nullptr) return result;
//         postOrder(root, result);
//         return result;
//     }
//     void postOrder(TreeNode* root, vector<int> & result) {
//         if (root == nullptr) return;
//         postOrder(root->left, result);
//         postOrder(root->right, result);
//         result.push_back(root->val);
//     }
// };

// Iterative
// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         deque<int> result;
//         if (root == nullptr) {
//             vector<int> vec;
//             return vec;
//         }
//         stack<TreeNode*> myStack;
//         myStack.push(root);
//         while (!myStack.empty()) {
//             TreeNode* curr = myStack.top();
//             myStack.pop();
//             if (curr != nullptr) {
//                 result.push_front(curr->val);
//                 myStack.push(curr->left);
//                 myStack.push(curr->right);
//             }
//         }
//         return vector<int>vec(result.begin(), result.end());
//     }
// };


// iterative
// store visited node on the stack to ensure that we can revisit its left child after we visit its right child
class Solution{
    public:
        vector<int> postorderTraversal(TreeNode* root) {
            stack<TreeNode*> Stack;
            deque<int> res;
            TreeNode* curr = root;
            while (!Stack.empty() || curr != nullptr) {
                if (curr != nullptr) {
                    Stack.push(curr);
                    res.push_front(curr->val);
                    curr = curr->right;
                }
                else {
                    TreeNode* node = Stack.top();
                    Stack.pop();
                    curr = node->left;
                }
            }
            return vector<int>(res.begin(), res.end());
        }
};
// @lc code=end

// s:
// r: 4, 5, 3, 6, 2, 8, 7, 1
// t:
//             1
//         /       \
//         2       7
//     /   \       /
//     3   6      8
// /     \
// 4      5

