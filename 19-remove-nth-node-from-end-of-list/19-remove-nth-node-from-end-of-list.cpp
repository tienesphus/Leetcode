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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length_of_list = 1;
        ListNode* temp = head;
        while (temp->next) {
            length_of_list++;
            temp = temp->next;
        }
        
        if (length_of_list == n)
            return head->next;
        
        ListNode* temp2 = head;
        for (int i = 0; i < length_of_list - n - 1; i++)
            temp2 = temp2->next;
        
        temp2->next = temp2->next->next;
        return head;
    }
};