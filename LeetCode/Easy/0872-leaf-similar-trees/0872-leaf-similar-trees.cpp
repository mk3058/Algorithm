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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<TreeNode *> leaves1, leaves2;
        
        preorderTraversal(root1, leaves1);
        preorderTraversal(root2, leaves2);
        
        if (leaves1.size() != leaves2.size()) {
            return false;
        }
        for(int i = 0; i < leaves1.size(); i++) {
            if (leaves1[i]->val != leaves2[i]->val) {
                return false;
            }
        }
        return true;
    }
    
    void preorderTraversal(TreeNode *root, vector<TreeNode *> &leaves) {
        if (!(root->left) && !(root->right)) {
            leaves.push_back(root);
        }
        if (root->left) {
            preorderTraversal(root->left, leaves);
        }
        if (root->right) {
            preorderTraversal(root->right, leaves);
        }
    }
};