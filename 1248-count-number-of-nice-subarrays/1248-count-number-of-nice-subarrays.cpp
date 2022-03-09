class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int oddCount = 0;
        int ans = 0;
        int n = nums.size();
        
        vector<int> prefixCount(nums.size() + 1, 0);
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 1)
                oddCount++;
            prefixCount[i + 1] = oddCount;
        }
           
        return getCount(prefixCount, k);
    }
    
    int getCount(vector<int>& prefixCount, int k) {
        vector<int> temp(prefixCount.size(), 0);
        int ans = 0;
        temp[0] = 0;
        
        int rightPtr = 1;
        int leftPtr = 0;
        
        while (rightPtr < prefixCount.size()) {
            if (prefixCount[rightPtr] == prefixCount[rightPtr-1])
                temp[rightPtr] = temp[rightPtr - 1];
            int cur = prefixCount[rightPtr] - prefixCount[leftPtr];
            if (cur == k)
                temp[rightPtr]++;
            if (cur < k)
                rightPtr++;
            else leftPtr++;
        }
        
        for (auto& ele: temp)
            ans += ele;
        
        return ans;
    }
};

// {0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2}
// {0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4}

 