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
    int goodNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        int goodNodes = 0;
        dfs(root, INT_MIN, goodNodes);
        return goodNodes;
    }
    
    // depth-first-search by preorder traversal 
    void dfs(TreeNode *node, int max, int &goodNodeCount) {
        if (node->val >= max) {
            max = node->val;
            goodNodeCount++;
        }
        
        if (node->left) {
            dfs(node->left, max, goodNodeCount);
        }
        if (node->right) {
            dfs(node->right, max, goodNodeCount);
        }
    }
};