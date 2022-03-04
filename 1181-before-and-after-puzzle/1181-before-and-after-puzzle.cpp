class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        unordered_map<string,vector<int>> pendingWords;
        set<string> ans;
        
        for (int i = 0; i < phrases.size(); i++) {
            string lastWord = findLastWord(phrases[i]);
            auto it = pendingWords.find(lastWord);
            
            if (it != pendingWords.end())
                it->second.push_back(i);
            else
                pendingWords.insert(make_pair(lastWord,vector<int>{i}));
        }
        
        for (int i = 0; i < phrases.size(); i++) {
            string firstWord = findFirstWord(phrases[i]);
            auto it = pendingWords.find(firstWord);
            
            if (it == pendingWords.end())
                continue;
            
            for (auto& idx: it->second) {
                if (idx == i)
                    continue;
                
                string toBePushed = phrases[idx] + phrases[i].substr(firstWord.size(), phrases[i].size() - firstWord.size());   
                ans.insert(toBePushed);
            }
        }

        return vector<string>(ans.begin(), ans.end());
    }
    
    string findLastWord(string s) {
        return s.substr(s.find_last_of(' ') + 1, s.size() - s.find_last_of(' ') + 1);   
    }
    
    string findFirstWord(string s) {
        return s.substr(0, s.find(' '));
    }
};