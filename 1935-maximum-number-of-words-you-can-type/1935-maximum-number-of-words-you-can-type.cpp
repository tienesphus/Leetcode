class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> brokenSet;
        for (auto& c: brokenLetters)
            brokenSet.insert(c);
        
        int ans = 0;
        
        stringstream ss(text);
        string word;
        
        while (getline(ss, word, ' ')) {
            bool canType = true;
            for (auto& c: word) {
                auto it = brokenSet.find(c);
                if (it != brokenSet.end()) {
                    canType = false;
                }
            }
            if (canType) ans++;
        }
        
        return ans;
    }
};