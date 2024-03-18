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
    ListNode* reverseList(ListNode* head) {
        
        if (!head) {
            return head;
        }
        
        ListNode *reversed = nullptr;
        reverse(head, &reversed);
        return reversed;
    }
    
    ListNode *reverse(ListNode *head, ListNode **reversedHead) {
        if (head->next) {
            ListNode *tmp = head->next;
            head->next = nullptr;
            return reverse(tmp, reversedHead)->next = head;
        } else {
            *reversedHead = head;
            return head;
        }
    }
};