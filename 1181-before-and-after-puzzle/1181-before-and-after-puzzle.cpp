class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        unordered_map<string,vector<int>> pendingWords;
        set<string> ans;
        
        //push all last words into a map with its index
        for (int i = 0; i < phrases.size(); i++) {
            string lastWord = findLastWord(phrases[i]);
            auto it = pendingWords.find(lastWord);
            
            if (it != pendingWords.end())
                it->second.push_back(i);
            else
                pendingWords.insert(make_pair(lastWord,vector<int>{i}));
        }
        
        //for all first words
        for (int i = 0; i < phrases.size(); i++) {
            //check map for first word
            string firstWord = findFirstWord(phrases[i]);
            auto it = pendingWords.find(firstWord);
            
            if (it == pendingWords.end())
                continue;
            
            
            for (auto& idx: it->second) {
                // skip phrase with same first and last word
                if (idx == i)
                    continue;
                
                //concat and push
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