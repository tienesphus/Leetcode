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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* mid = getMid(head);
        ListNode* sortedLeft = sortList(head);
        ListNode* sortedRight = sortList(mid);
        return merge(sortedLeft,sortedRight);
    }
    
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(-1);
        ListNode* ptr = &dummy;
        
        while (left && right) {
            if (left->val < right->val) {
                ptr->next = left;
                left = left->next;
            } else {
                ptr->next = right;
                right = right->next;
            }
            ptr = ptr->next;
        }
        
        if (left) 
            ptr->next = left;
        else ptr->next = right;
        
        return dummy.next;
    }
    
    ListNode* getMid(ListNode* head) {
        ListNode* slowPtr = nullptr;
        ListNode* fastPtr = head;
        
        while (fastPtr != nullptr && fastPtr->next != nullptr) {
            slowPtr = (slowPtr == nullptr) ? head : slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        
        ListNode* mid = slowPtr->next;
        slowPtr->next = nullptr;
        
        return mid;
    }
};