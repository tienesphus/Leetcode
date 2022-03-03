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
    int sumNumbers(TreeNode* root) {
        vector<int> nums;
        SumRootToLeaf(root, 0, nums);
        int ans = 0;
        
        for (auto& num: nums) {
            ans += num;    
        }
        
        return ans;
    }
    
    void SumRootToLeaf(TreeNode* root, int curNum, vector<int>& nums) {
        if ((!root->left) && (!root->right)) {
            nums.push_back(curNum*10 + root->val);
            return;
        }
        
        if (root->left)
            SumRootToLeaf(root->left, curNum*10 + root->val, nums);
        
        if (root->right)
            SumRootToLeaf(root->right, curNum*10 + root->val, nums);
        
        return;
    }
};