class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> baseMap;
        int substrLength = words.size() * words[0].size();
        
        if (s.size() < substrLength)
            return {};
        
        vector<int> ans;
        for (auto& ele: words) {
            auto it = baseMap.find(ele);
            
            if (it != baseMap.end()) {
                it->second += 1;
            } else {
                baseMap.insert(make_pair(ele, 1));
            }
        }
        
        
        for (int i = 0; i <= s.size()-substrLength; i++) {
            string cursubstr = s.substr(i, substrLength);
            if (calculateHashTable(cursubstr,words[0].size(), baseMap))
                ans.push_back(i);
        }
        return ans;
    }
    
    bool calculateHashTable(string s, int n, unordered_map<string,int> base) {
        for (int i = 0; i < s.size(); i += n) {
            string cur_substr = s.substr(i,n);
            auto it = base.find(cur_substr);
            
            if (it == base.end()) {
                return false;
            } else {
                if (it->second > 0)
                    it->second -= 1;
                else return false;
            }
        }
        
        return true;
    }
};