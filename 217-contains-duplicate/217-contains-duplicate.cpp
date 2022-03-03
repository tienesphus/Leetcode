class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> ht;
        
        for (int i = 0; i < nums.size(); i++) {
            auto it = ht.find(nums[i]);
            
            if (it != ht.end()) {
                return true;
            } else {
                ht.insert(make_pair(nums[i], 1));
            }
        }
        return false;
    }
};