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
        stack<int> nodeStack;
        while (head != nullptr) {
            nodeStack.push(head->val);
            head = head->next;
        }
        
        ListNode* ans = new ListNode(0);
        ListNode* anchor = ans;
        
        while (!nodeStack.empty()) {
            ListNode* temp = new ListNode(nodeStack.top());
            nodeStack.pop();
            ans->next = temp;
            ans = ans->next;
        }
        
        return anchor->next;
    }
};