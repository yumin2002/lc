/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
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
struct MyNode {
    TreeNode* node;
    int row;
    int col;
};
bool comp(MyNode first, MyNode second) {
    if (first.col == second.col && first.row == second.row) {
        TreeNode* node1 = first.node;
        TreeNode* node2 = second.node;
        return node1->val < node2->val;
    }
    else if (first.col == second.col) {
        return first.row < second.row;
    }
    return first.col < second.col;
}
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // dfs
        deque<MyNode> temp;
        stack<MyNode> s;
        s.push(MyNode{root, 0, 0});
        while (!s.empty()) {
            MyNode curr = s.top();
            s.pop();
            if (curr.node != nullptr) {
                temp.push_back(curr);
                MyNode left{(curr.node)->left, curr.row + 1, curr.col - 1};
                MyNode right{(curr.node)->right, curr.row + 1, curr.col + 1};
                s.push(left);
                s.push(right);
            }
        }

        // sort
        sort(temp.begin(), temp.end(), comp);
        vector<vector<int>> res;
        MyNode prev;
        MyNode curr = temp.front();
        while (!temp.empty()) {
            curr = temp.front();
            temp.pop_front();
            if (res.empty() || curr.col != prev.col) {
                res.push_back({});
            }
            cout << res.empty();
            res[res.size()-1].push_back((curr.node)->val);
            prev = curr;
        }
        return res;
    }
};
// @lc code=end

