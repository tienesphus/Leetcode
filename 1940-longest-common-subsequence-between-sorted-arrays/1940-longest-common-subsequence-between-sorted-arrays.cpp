class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int m = arrays[0].back();
        
        vector<int> countTable(m+1, 0);
        
        for (auto& array: arrays) {
            for (auto& ele: array) {
                if (ele > m)
                    continue;
                countTable[ele] += 1;
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < countTable.size(); i++) {
            if (countTable[i] == n) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};