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
    int maxDepth(TreeNode* root) {
        int maxLevel = 0;
        
        preorderTraversal(root, 0, &maxLevel);
        return maxLevel;
    }
    
    void preorderTraversal(TreeNode *root, int currentLevel, int *maxLevel) {
        if (root) {
            if (++currentLevel > *maxLevel) {
                *maxLevel = currentLevel;
            }

            if (root->left) {
                preorderTraversal(root->left, currentLevel, maxLevel);
            }
            if (root->right) {
                preorderTraversal(root->right, currentLevel, maxLevel);
            }
        }
    }
};