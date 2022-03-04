class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int lastElement = 0;
        int ans = 0;
        
        for (int i = 2; i < n; i++) {
            bool checkArithmetic = ((nums[i] - nums[i-1]) == (nums[i-1] - nums[i-2]));
            if (checkArithmetic) {
                ans += (++lastElement);
            } else {
                lastElement = 0;
            }

        }
        
        return ans;
    }
};