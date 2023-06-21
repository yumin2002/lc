/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (!root) return res;
        q.push(root);
        while (!q.empty()) {
            int currSize = q.size();
            vector<int> level;
            for (int i = 0; i < currSize; i++) {
                TreeNode* curr = q.front();
                q.pop();
                level.push_back(curr->val);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            res.push_back(level);
        }
        return vector<vector<int>> (res.rbegin(), res.rend());

    }
};
// @lc code=end

// some java recursice solution
// class Solution {
//     List<List<Integer>> levels = new ArrayList<List<Integer>>();

//     public void helper(TreeNode node, int level) {
//         // start the current level
//         if (levels.size() == level)
//             levels.add(new ArrayList<Integer>());

//          // append the current node value
//          levels.get(level).add(node.val);

//          // process child nodes for the next level
//          if (node.left != null)
//             helper(node.left, level + 1);
//          if (node.right != null)
//             helper(node.right, level + 1);
//     }
    
//     public List<List<Integer>> levelOrderBottom(TreeNode root) {
//         if (root == null) return levels;
//         helper(root, 0);
//         Collections.reverse(levels);
//         return levels;
//     }
// }