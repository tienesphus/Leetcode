class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        unordered_map<char, int> ht;
        int ans = 0;
        int n = s.length();
        while (right < n) {
            auto it = ht.find(s[right]);
            if (it != ht.end()) {
                left = max(it->second + 1,left);
                it->second = right;
            } else {
                ht.insert(make_pair(s[right],right)); 
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};