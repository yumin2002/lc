/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
// iteration
// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         stack<TreeNode*> s1;
//         stack<TreeNode*> s2;
//         s1.push(p);
//         s2.push(q);
//         while (!s1.empty() && !s2.empty()) {
//             TreeNode* curr1 = s1.top();
//             TreeNode* curr2 = s2.top();
//             s1.pop();
//             s2.pop();
//             if ((curr1 && !curr2) || (!curr1 && curr2)) return false;
//             if (curr1 && curr2) {
//                 if (curr1->val != curr2->val) return false;
//                 s1.push(curr1->left);
//                 s1.push(curr1->right);
//                 s2.push(curr2->left);
//                 s2.push(curr2->right);
//             }
//         }
//         if (!s1.empty() || !s2.empty()) {
//             return false;
//         }
//         return true;
//     }
// };

// recursion
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->right, q->right) || isSameTree(p->left, q->left);
    }
}
// @lc code=end

