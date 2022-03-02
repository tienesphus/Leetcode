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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = new ListNode();
        ListNode* anchor = result;
        while (true) {
            int cur_min = INT_MAX;
            ListNode** cur_min_node;
            for (auto& lk: lists) {
                if (lk == nullptr) {
                    continue;
                } else if (lk->val < cur_min) {
                    cur_min = lk->val;
                    cur_min_node = &lk;
                }
            }
            if (cur_min == INT_MAX)
                break;
            ListNode* temp = new ListNode(cur_min);
            result->next = temp;
            result = result->next;
            (*cur_min_node) = (*cur_min_node)->next;
        }
        return anchor->next;
    }
};