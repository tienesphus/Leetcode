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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return findDepth(root, 1);
    }
    
    int findDepth(TreeNode* root, int currDepth) {
        if (root == nullptr)
            return currDepth - 1;
        
        return max(findDepth(root->left, currDepth + 1),
                   findDepth(root->right, currDepth + 1));

    }
};