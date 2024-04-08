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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        traverse(root, low, high, sum);
        
        return sum;
    }
    
    void traverse(TreeNode *root, int low, int high, int &sum) {
        if (!root) {
            return ;
        }
        
        if (root->val > low)
            traverse(root->left, low, high, sum);
        if (root->val < high)
            traverse(root->right, low, high, sum);
        if (low <= root->val && root->val <= high) {
            sum += root->val;
        }
    }
};