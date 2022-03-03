class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int n = nums.size();
        if (nums[0] < nums[n - 1])
            return nums[0];
        
        int left = 0;
        int right = n - 1;
        
        return findRotatedIndex(left,right,nums);
    }
    
    int findRotatedIndex(int left, int right, vector<int>& nums) {
        int mid = left + (right - left) / 2;
        if (nums[left] < nums[right]) return left;
        if (nums[mid] > nums[mid + 1]) return nums[mid + 1];
        if (nums[0] > nums[mid]) 
            return findRotatedIndex(left, mid, nums);
        else 
            return findRotatedIndex(mid, right, nums);
    }
};