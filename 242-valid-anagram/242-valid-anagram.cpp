class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        
        calculateHT(s,m1);
        calculateHT(t,m2);
        
        return m1 == m2;
    }
    
    void calculateHT(string s, unordered_map<char,int>& ht) {
        for (auto& c: s) {
            auto it = ht.find(c);
            if (it != ht.end()) {
                it->second += 1;
            }
            else {
                ht.insert(make_pair(c,1));
            }
        }
    }
};