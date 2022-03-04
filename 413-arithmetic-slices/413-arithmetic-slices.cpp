class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        
        for (int i = 2; i < n; i++) {
            bool checkArithmetic = ((nums[i] - nums[i-1]) == (nums[i-1] - nums[i-2]));
            if (checkArithmetic)
                dp[i] = dp[i-1] + 1;
        }
        
        int ans = 0;
        for (auto& ele: dp)
            ans += ele;
        
        return ans;
    }
};