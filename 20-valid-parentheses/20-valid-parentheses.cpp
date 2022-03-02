class Solution {
public:
    bool isValid(string s) {
        if (s.size() < 2)
            return false;
        
        stack<char> stk;
        
        for (auto& c: s) {
            if (c == '{' || c == '(' || c == '[') {
                stk.push(c);
                continue;
            }
            
            if (stk.empty()) return false;
            char cur_c = stk.top();
            switch (cur_c) {
                case '(':
                    if (c != ')')
                        return false;
                    break;
                case '{':
                    if (c != '}')
                        return false;
                    break;
                case '[':
                    if (c != ']')
                        return false;
                    break;
                default:
                    break;
            }
            stk.pop();
        }
        return stk.empty();
    }
};