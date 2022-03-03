/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> ht;
        while (head) {
            auto it = ht.find(head);
            if (it != ht.end())
                return true;
            else {
                ht.insert(head);
            }
            head = head->next;
        }
        return false;
    }
};