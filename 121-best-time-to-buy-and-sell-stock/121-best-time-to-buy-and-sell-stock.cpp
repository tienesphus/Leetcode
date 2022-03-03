class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curProfit = 0;
        int curMin = INT_MAX;
        int curMax = INT_MIN;
        
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] > curMax) curMax = prices[i];
            if (prices[i] < curMin) curMin = prices[i];    
            
            if (prices[i] - curMin > curProfit) curProfit = prices[i] - curMin; 
        }
        return curProfit;
    }
};