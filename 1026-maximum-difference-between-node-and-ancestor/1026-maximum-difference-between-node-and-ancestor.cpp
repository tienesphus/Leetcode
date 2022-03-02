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
    
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = INT_MIN;
        maxAncestorDiff(root->left, root->val, root->val, maxDiff);
        maxAncestorDiff(root->right, root->val, root->val, maxDiff);
        return maxDiff;
    }
    
    void maxAncestorDiff(TreeNode* root, int curMax, int curMin, int& maxDiff) {
        if (root == nullptr)
            return;
        
        curMax = max(root->val, curMax);
        curMin = min(root->val, curMin);
        maxDiff = max(maxDiff, abs(curMax - curMin));
        
        maxAncestorDiff(root->left, curMax, curMin, maxDiff);
        maxAncestorDiff(root->right, curMax, curMin, maxDiff);
    }
};