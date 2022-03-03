class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        vector<int> binary(flips.size(), 0);
        int pointer = 0;
        int ans = 0;
        
        for (int i = 0; i < flips.size(); i++) {
            binary[flips[i] - 1] = 1;
            while (pointer < flips.size() && binary[pointer] != 0)
                pointer++;
            
            if (pointer >= i+1)
                ans++;
        }
        
        return ans;
    }
};