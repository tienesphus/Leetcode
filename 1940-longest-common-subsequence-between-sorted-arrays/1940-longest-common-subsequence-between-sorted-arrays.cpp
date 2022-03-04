class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        map<int,int> countTable;
        int n = arrays.size();
        
        for (auto& array: arrays) {
            for (auto& ele: array) {
                auto it = countTable.find(ele);
                
                if (it != countTable.end())
                    it->second += 1;
                else {
                    countTable.insert(make_pair(ele, 1));
                }
            }
        }
        
        
        vector<int> ans;
        for (auto& pair: countTable) {
            if (pair.second == n)
                ans.push_back(pair.first);
        }
        
        return ans;
    }
};


