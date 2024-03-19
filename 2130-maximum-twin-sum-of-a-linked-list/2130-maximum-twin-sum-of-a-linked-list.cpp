/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    
    int pairSum(ListNode* head) {
        stack<ListNode *> s;
        int max = -1;
        
        ListNode *tmp = head;
        while (tmp) {
            s.push(tmp);
            tmp = tmp -> next;
        }
        
        while (true) {
            int sum = head->val + s.top()->val;
            s.pop();
            if (sum > max) {
                max = sum;
            }
            if (s.top() == head) {
                break;
            }
            head = head->next;
        }
        return max;
    }
};