class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int pricesSize = prices.size();
        ans += pricesSize;
        
        if (pricesSize == 1)
            return ans;
        
        // find all the longest non overlapping smooth periods
        vector<long> periodsLength;
        int curVal = prices[0];
        int curStreak = 1;
        for (int i = 1; i < pricesSize; ++i) {
            bool streakContinue = (curVal == prices[i] + 1);
            
            if (streakContinue)
                curStreak++;
            
            if (curStreak > 1 && (!streakContinue || i == pricesSize - 1)) {
                periodsLength.push_back(curStreak);
                curStreak = 1;
            }
            
            curVal = prices[i];
        }
        
        // calculate the total number of smooth periods based on that
        for (auto& period: periodsLength) {
            ans += (period - 1)*(period)/2;
        }
        
        // return the answer
        return ans;
    }
};

// find all the longest non overlapping smooth periods
// calculate the total number of smooth periods based on that
//
