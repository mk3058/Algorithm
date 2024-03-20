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
    ListNode* oddEvenList(ListNode* head) {
        
        if (!head || !(head->next)) {
            return head;
        }
        
        ListNode *evenHead = head->next;
        ListNode *odd = nullptr, *even = nullptr;
        ListNode *tmp = head;
        bool isEven = false;
        
        while(tmp) {
            if (isEven) {            
                if (even) {
                    even->next = tmp;
                    even = even->next;
                }
                else
                    even = tmp;
            } else {
                if (odd){
                    odd->next = tmp;
                    odd = odd->next;
                }
                else
                    odd = tmp;
            }

            tmp = tmp->next;
            isEven = !isEven;
        }
        odd->next = evenHead;
        even->next = nullptr;
        return head;
    }
};