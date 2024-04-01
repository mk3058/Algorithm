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
    bool isUnivalTree(TreeNode* root) {
        bool flag = true;
        checkUnivalued(root, root->val, flag);
        return flag;
    }
    
    void checkUnivalued(TreeNode *node, int &val, bool &flag) {
        if (node->val != val) {
            flag = false;
        }
        if (node->left) {
            checkUnivalued(node->left, val, flag);
        }
        if (node->right) {
            checkUnivalued(node->right, val, flag);
        }
    }
};