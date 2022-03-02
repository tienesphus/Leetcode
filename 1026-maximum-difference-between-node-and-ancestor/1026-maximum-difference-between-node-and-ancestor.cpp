/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDiff = INT_MIN;
    int maxAncestorDiff(TreeNode* root) {
        maxAncestorDiff(root->left, root->val, root->val);
        maxAncestorDiff(root->right, root->val, root->val);
        return maxDiff;
    }
    
    void maxAncestorDiff(TreeNode* root, int curMax, int curMin) {
        if (root == nullptr)
            return;
        
        curMax = max(root->val, curMax);
        curMin = min(root->val, curMin);
        maxDiff = max(maxDiff, abs(curMax - curMin));
        
        maxAncestorDiff(root->left, curMax, curMin);
        maxAncestorDiff(root->right, curMax, curMin);
    }
};