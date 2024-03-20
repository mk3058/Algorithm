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
        
        s.push(head);
        ListNode *tmp = head->next;
        int length = 1;
        while (tmp) {
            if (!(length++ % 2)) {
                s.push(s.top()->next);
            }
            tmp = tmp -> next;
        }
        
        ListNode *middleAfter = s.top()->next;
        while (!s.empty()) {
            int sum = middleAfter->val + s.top()->val;
            s.pop();
            if (sum > max) {
                max = sum;
            }
            middleAfter = middleAfter -> next;
        }
        return max;
    }
};