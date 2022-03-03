class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixSum(nums.size());
        prefixSum[0] = nums[0];
        vector<int> suffixSum(nums.size());
        suffixSum[suffixSum.size() - 1] = nums[nums.size() - 1];
        
        for (int i = 1; i < prefixSum.size(); i++) {
            prefixSum[i] = nums[i] * prefixSum[i- 1];
        }
        
        for (int i = suffixSum.size() - 2; i > -1; i--) {
            suffixSum[i] = nums[i] * suffixSum[i + 1];
        }
        
        vector<int> ans(nums.size());
        
        for (int i = 0; i < ans.size(); i++) { 
            if (i == 0) 
                ans[i] = suffixSum[i+1];
            else if (i == ans.size() - 1) 
                ans[i] = prefixSum[i-1];
            else
                ans[i] = suffixSum[i+1] * prefixSum[i-1];
        }
        return ans;
    }
};