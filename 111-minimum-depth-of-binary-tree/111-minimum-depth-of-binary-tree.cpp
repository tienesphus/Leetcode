class Solution {
public:
    void dfs(TreeNode* tn, int cur_depth)
    {
        if (tn->left == nullptr && tn->right == nullptr) {
            if (cur_depth < result)
                result = cur_depth;
        }
            
        if (tn->left != nullptr) {
            int new_depth = cur_depth + 1;
            dfs(tn->left,new_depth);
        }
            
        if (tn->right != nullptr) {
            int new_depth = cur_depth + 1;
            dfs(tn->right,new_depth);
        }
    }
    
    int result = INT_MAX;
	int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

		dfs(root,1);
		return result;
    }
};
