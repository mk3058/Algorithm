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
    stack<int> values;
    
    int goodNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        int goodNodes = 0;
        
        dfs(root, goodNodes);
        return goodNodes;
    }
    
    // depth-first-search by preorder traversal 
    void dfs(TreeNode *node, int &goodNodeCount) {
        if (values.empty() || node->val >= values.top()) {
            values.push(node->val);
            goodNodeCount++;
        }
        if (node->left) {
            dfs(node->left, goodNodeCount);
        }
        if (node->right) {
            dfs(node->right, goodNodeCount);
        }
        if (node->val == values.top()) {
            values.pop();
        }
    }
};