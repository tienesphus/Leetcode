class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int m = arrays[0].back();
        
        vector<int> countTable(m+1, 0);
        vector<int> ans;
        
        // O(n) with n is the number of elements in all the arrays
        for (auto& array: arrays) {
            for (auto& ele: array) {
                if (ele > m)
                    continue;
                countTable[ele] += 1;
                if (countTable[ele] == n)
                    ans.push_back(ele);
            }
        }
        // O(m) with m is the largest number out of all elements in arrays
        return ans;
    }
};