/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
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
//     int deepestLeavesSum(TreeNode* root) {
//         queue<TreeNode*> q;
//         int sum = root->val;
//         q.push(root);
//         while (!q.empty()) {
//             int currSum = 0;
//             int currSize = q.size();
//             int count = 0;
//             for (int i = 0; i < currSize; i++) {
//                 TreeNode* curr = q.front();
//                 q.pop();
//                 if (curr->left) {
//                     count ++;
//                     q.push(curr->left);
//                     currSum += curr->left->val;
//                 }
//                 if (curr->right) {
//                     count++;
//                     q.push(curr->right);

//                     currSum += curr->right->val;
//                 }
//             }
//             if (count > 0) sum = currSum;
            
//         }
//         return sum;
//     }
// };
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int res = 0；
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            res = 0
            int currSize = q.size();
            for (int i = 0; i < currSize; ++i) {
                TreeNode* node = q.front(); 
                q.pop();
                res += node->val;
                if (node->right) q.push(node->right);
                if (node->left)  q.push(node->left);
            }
        }
        return res;
    }
};
// @lc code=end

