/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> nodes;
        inorder(root, nodes);
        auto it = find(nodes.begin(), nodes.end(), p);
        advance(it,1);
        if (it == nodes.end()) return nullptr;
        else return *it;
    }
    
    void inorder(TreeNode* root, vector<TreeNode*>& nodes) {
        if (!root)
            return;
        inorder(root->left,nodes);
        nodes.push_back(root);
        inorder(root->right,nodes);
    }
    
};