class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            bool isArithmetic = true;

            for (int j = i + 2; j < n; j++) {
                if (!isArithmetic)
                    break;
                isArithmetic = ((nums[j] - nums[j-1]) == (nums[j-1] - nums[j-2]));
                if (j - i >= 2 && isArithmetic)
                    count++;
            }
        }
        return count;
    }
};