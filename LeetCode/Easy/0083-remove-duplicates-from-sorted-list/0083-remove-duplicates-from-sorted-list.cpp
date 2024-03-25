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
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> values;
        
        while (head) {
            values.insert(head->val);
            head = head->next;
        }
        
        ListNode *newList = nullptr;
        ListNode *last = nullptr;
        for (int value : values) { 
            if (newList) {
                last -> next = new ListNode(value);
                last = last->next;
            } else {
                newList = new ListNode(value);
                last = newList;
            }
        }
        return newList;
    }
};