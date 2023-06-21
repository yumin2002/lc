/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/


// iterative solution
// mem optimized
// time O(n) mem O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> Queue;
        vector<vector<int>> res;
        if (root == nullptr) return res;
        Queue.push(root);
        
        while (!Queue.empty()) {
            res.push_back({});
            int currSize = Queue.size();
            for (int i = 0; i < currSize; i++) {
                Node* curr = Queue.front();
                Queue.pop();
                res.back().push_back(curr->val);
                for (int j = 0; j < curr->children.size(); j++) {
                    Queue.push(curr->children[j]);
                }
            }
        }
        return res;
    }
};
// @lc code=end


//         1
//   3     2      4
//  5 6

// queue1: 3 2 4


// using preorder, insert into corresponding level index
// Author: Huahua
// Running time: 44 ms
// class Solution {
// public:
//   vector<vector<int>> levelOrder(Node* root) {
//     vector<vector<int>> ans;
//     preorder(root, 0, ans);
//     return ans;
//   }
// private:
//   void preorder(Node* root, int d, vector<vector<int>>& ans) {
//     if (root == nullptr) return;
//     while (ans.size() <= d) ans.push_back({});
//     ans[d].push_back(root->val);
//     for (auto child : root->children)
//       preorder(child, d + 1, ans);
//   }
// };