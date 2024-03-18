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
    stack<ListNode*> s;
    
    ListNode* reverseList(ListNode* head) {
        
        ListNode *reversed = nullptr;
        
        // When list is empty, return the original list
        if (!head) {
            return head;
        }
        
        // push all nodes into the stack to reverse the list
        while (head) {
            s.push(head);
            head = head->next;
        }
        
        // Pop in the stack and reverse connect nodes
        reversed = s.top();
        while (true) {
            ListNode *node = s.top();
            s.pop();
            if (s.empty()) {
                node->next = nullptr;
                break;
            }
            node->next = s.top();
        }
        
        return reversed;
    }
};