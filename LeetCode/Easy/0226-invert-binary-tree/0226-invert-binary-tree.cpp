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
    TreeNode* invertTree(TreeNode* root) {
        invertBinaryTree(root);
        
        return root;
    }
    
    void invertBinaryTree(TreeNode *root) {
        if (!root) {
            return ;
        }
        
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }
};