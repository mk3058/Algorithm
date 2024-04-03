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

 /**
 Pseudo Palindromic: 경로상의 노드 조합 중 한개 이상이 펠린드롬을 이루는 경우
    -> 노드가 한개일때 가능

 sol1 : dfs로 경로상의 node value를 collect하고, 펠린드롬 검사
    -> 시간복잡도 O(L!) / O(n), 공간복잡도 O(n)
 sol2 : dfs로 경로상의 node value를 count (value 범위  1-9)
    -> 전체 노드 개수가 짝수개인경우 : count가 모두 짝수여야 팰린드롬
    -> 전체 노드 개수가 홀수개인경우 : 한개 이하의 원소가 홀수개, 나머지 짝수개
    -> 시간복잡도 O(n), 공간복잡도 O(1)
 */
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int countValue[10] = {};
        int palindromCount = 0;

        DFS(root, countValue, palindromCount);
        return palindromCount;
    }
    
    void DFS(TreeNode *root, int *count, int &palindromCount) {
        count[root->val]++;
        if (root->left)
            DFS(root->left, count, palindromCount);
        if (root->right)
            DFS(root->right, count, palindromCount);
        if (!root->left && !root->right) {
            if (isPseudoPalindromic(count)) {
                palindromCount++;
            }
        }
        count[root->val]--;
    }

    bool isPseudoPalindromic(int *count) {
        int totalValueCount = 0;
        bool hasOddValue = false;

        for(int i = 1; i <= 9; i++) {
            totalValueCount++;
            if (count[i] % 2 != 0) {
                if (hasOddValue) {
                    return false;
                }
                hasOddValue = true;
            }
        }

        if (hasOddValue && !(totalValueCount % 2)) {
            return false;
        }
        return true;
    }
};