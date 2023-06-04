/*
 * @lc app=leetcode id=285 lang=cpp
 *
 * [285] Inorder Successor in BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//     TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
//         if (!root || !p) {
//             return nullptr;
//         }
//         TreeNode* successor = nullptr;
//         while (root) {
//             if (root->val <= p->val) {
//                 root = root->right;
//             }
//             else {
//                 successor = root;
//                 root = root->left;
//             }
//         }
//         return successor;

//     }
// };
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {

        //Case 1 : Right Subtree is not empty
        if( p->right != NULL )
        {
             TreeNode* curr = p->right;
            
             //loop down to find the leftmost leaf
              while (curr->left != NULL)
                curr = curr->left;

              return curr;
        }
        
        
        // Case 2: Right tree empty. Now Start from root and search for successor down the tree
        TreeNode *succ = NULL;
        while (root != NULL)
        {
            if (p->val < root->val){
                succ = root;
                root = root->left;
            }
            else root = root->right;
            // else if(p->val == root->val)
            //    break;
        }

        return succ;
        
    }
    
};
// @lc code=end

