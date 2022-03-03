class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0;
        int cur_gas = 0;
        int starting_station = 0;;
        
        for (int i = 0; i < gas.size(); i++)
        {
            int relative_gas = gas[i] - cost[i];
            cur_gas += relative_gas;
            total_gas += relative_gas;
            if (cur_gas < 0)
            {
                starting_station = i+1;
                cur_gas = 0;
                continue;
            }
        }
        
        if (total_gas >= 0)
            return starting_station;
        else
            return -1;
    }
};