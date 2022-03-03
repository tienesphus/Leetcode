class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        int result = nums[0];
        int cur_min = nums[0];
        int cur_max = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            int temp_max = max(nums[i], max(nums[i]*cur_min, nums[i]*cur_max));
            cur_min = min(nums[i], min(nums[i]*cur_min, nums[i]*cur_max));
            cur_max = temp_max;
            result = max(cur_max,result);
        }
        
        return result;
    }
};