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
    
    ListNode* deleteMiddle(ListNode* head) {
        
        // Returns an empty list when the size of the list is 1 or less
        if (!head || !(head->next)) {
            return nullptr;
        }
    
        ListNode *prev = head;
        ListNode *tmp = head->next->next;
        int listSize = 2; // The minimum length of a list in this position is 2\
        // Only change the position of the center node when the list size is a multiple of 2, so update the position of the old node when it falls off by dividing by 2.
        while(tmp) {
            if (!(++listSize % 2)) {
                prev = prev->next;
            }
            tmp = tmp->next;
        }
        // Delete middle node
        prev->next = prev->next->next;
        return head;
    }
};