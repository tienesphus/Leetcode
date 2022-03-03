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
    int ans = 0;
    bool isUniValue(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            ans++;
            return true;
        }
            
        bool isUniVal = true;
        if (root->left) {
            isUniVal = isUniValue(root->left) && (isUniVal) && (root->val == root->left->val);
        }
            
        if (root->right) {
            isUniVal = isUniValue(root->right) && (isUniVal) && (root->val == root->right->val);
        }
        
        if (!isUniVal) return false;
        ans++;
        return true;
    }
    int countUnivalSubtrees(TreeNode* root) {
        if (root == nullptr)
            return 0;
        isUniValue(root);
        return ans;
    }
};