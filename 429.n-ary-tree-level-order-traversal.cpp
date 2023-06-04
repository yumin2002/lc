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
            for (int i = Queue.size(); i >= 1; i--) {
                Node* curr = Queue.front();
                Queue.pop();
                res.back().push_back(curr->val);
                for (int i = 0; i < curr->children.size(); i++) {
                    Queue.push(curr->children[i]);
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