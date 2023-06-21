/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
// recursive:
// class Solution {
// public:
//     // suppose root: M, subRoot: N.
//     // traverse root, at most M calls
//     bool isSubtree(TreeNode* root, TreeNode* subRoot) {
//         if (!subRoot) return false;
//         if (!root) return false;
//         if (root->val == subRoot->val && sameTree(root, subRoot)) return true;
//         return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
//     }

//     // traverse subroot, at most N calls
//     bool sameTree(TreeNode* root, TreeNode* subRoot) {
//         if (!root && !subRoot) return true;
//         if (root && !subRoot) return false;
//         if (!root && subRoot) return false;
//         if (root->val == subRoot->val) return sameTree(root->left, subRoot->left) && sameTree(root->right, subRoot->right);
//         return false;
//     }
// };

//  iterative
class Solution {
public:
    // suppose root: M, subRoot: N.
    // traverse root, at most M calls
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* curr = s.top();
            s.pop();
            if (curr) {
                if (isSame(curr, subRoot)) return true;
                s.push(curr->left);
                s.push(curr->right);
            }
        }
        return false;
    }
    bool isSame(TreeNode* root, TreeNode* subRoot) {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        s2.push(subRoot);
        while (!s1.empty() && !s2.empty()){
            TreeNode* first = s1.top();
            s1.pop();
            TreeNode* second = s2.top();
            s2.pop();
            if (!first && second) return false;
            if (!second && first) return false;
            if (first && second) {
                if (first->val != second->val) return false;
                s1.push(first->left);
                s1.push(first->right);
                s2.push(second->left);
                s2.push(second->right);
            }
        }
        if (!s1.empty() || !s2.empty()) return false;
        return true;
    }
};
// @lc code=end

//  Time complexity: O(MN).
//  Space complexity: O(M+N). Before calling the next isSubtree, all the sameTree calls are popped off from the call stack.

// TODO: Approach 2: string matching 
// TODO: Approach 3: tree hash