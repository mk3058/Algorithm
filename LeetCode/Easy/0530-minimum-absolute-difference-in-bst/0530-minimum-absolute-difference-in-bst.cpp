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
    int getMinimumDifference(TreeNode* root) {
        vector<int> values;
        int diff = INT_MAX;
        
        inOrderTraversal(root, values);
        for(int i = 1; i < values.size(); i++) {
            if (values[i] - values[i - 1] < diff)
                diff = values[i] - values[i - 1];
        }
        return diff;
    }
    
    void inOrderTraversal(TreeNode *node, vector<int> &values) {
        if (!node) {
            return ;
        }
        
        inOrderTraversal(node->left, values);
        values.push_back(node->val);
        inOrderTraversal(node->right, values);
    }
};