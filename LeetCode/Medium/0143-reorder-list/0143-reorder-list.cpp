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
    void reorderList(ListNode* head) {
        vector<ListNode *> nodes; nodes.reserve(50000);
        ListNode *tmp = head;

        while (tmp) {
            nodes.push_back(tmp);
            tmp = tmp->next;
        }

        tmp = head;
        for(int i = 1; i < nodes.size(); i++) {
            int idx = -1;

            if (i % 2 == 0) {
                idx = i / 2;
            } else {
                idx = nodes.size() - 1 - (i / 2);
            }

            tmp->next = nodes[idx];
            tmp = tmp->next;
            if (i == nodes.size() - 1) {
                tmp->next = nullptr;
            }
        }
    }
};