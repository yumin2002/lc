/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
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

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        stack<Node*> s;
        s.push(root);
        while (!s.empty()) {
            Node* curr = s.top();
            s.push(curr);
            s.pop()
            if (curr != nullptr) {
                for (int i = 0; i < curr->children; i++) {
                    s.push(curr->children[i]);
                }
            }
        }
        return vector<int>(res.rbegin(),res.rend());
    }
};
// @lc code=end

