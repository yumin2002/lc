/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
//     struct MyNode {
//         TreeNode* node;
//         int depth;
//     }
//     int maxDepth(TreeNode* root) {
//         if (!root) return 0;
//         int maxDepth = 0;
//         stack<MyNode> s;
//         s.push({root, 1});
//         while (!s.empty()) {
//             MyNode curr = s.top();
//             TreeNode* currNode = curr.node;
//             int currDep = curr.depth;
//             s.pop();
//             if (currNode->left) {
//                 maxDepth = max(maxDepth, currDep + 1);
//                 s.push({currNode->left, currDep + 1})
//             }
//             if (currNode->right) {
//                 maxDepth = max(maxDepth, currDep + 1);
//                 s.push({currNode->right, currDep + 1})
//             }
//         }
//         return maxDepth;
//     }
// };

// recursive
class Solution {
public:
  int maxDepth(TreeNode* root) {
    if (!root) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return max(l, r) + 1;
  }
};
// @lc code=end

