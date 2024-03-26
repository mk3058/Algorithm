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
        int goodNodes = 0;
        dfs(root, INT_MIN, goodNodes);
        return goodNodes;
    }
    
    // depth-first-search by preorder traversal 
    void dfs(TreeNode *node, int max, int &goodNodeCount) {
        if (!node) {
            return ;
        }
        
        if (node->val >= max) {
            max = node->val;
            goodNodeCount++;
        }
        dfs(node->left, max, goodNodeCount);
        dfs(node->right, max, goodNodeCount);
    }
};