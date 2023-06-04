/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
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

// class Solution {
// public:
//     vector<int> preorder(Node* root) {
//         vector<int> res;
//         preorderTraversal(root, res);
//         return res;
//     }
//     void preorderTraversal(Node* root, vector<int> & res) {
//         if (root == nullptr) return;
//         res.push_back(root->val);
//         for (int i = 0; i < root->children.size(); i++) {
//             preorderTraversal(root->children[i], res);
//         }
//     }
// };

class Solution {
    public:
        vector<int> preorder(Node* root) {
            stack<Node*> s;
            vector<int> res;
            s.push(root);
            while (!s.empty()) {
                Node* curr = s.top();
                s.pop();
                if (curr != nullptr) {
                    res.push_back(curr->val);
                    for (int i = curr->children.size(); i >= 0; i++) {
                        s.push(curr->children[i]);
                    }
                }
            }
            return res;
        }
};
// @lc code=end

