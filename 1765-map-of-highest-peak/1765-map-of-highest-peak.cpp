class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        
        vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
        
        vector<vector<int>> heights(m, vector<int>(n,-1));
        queue<pair<int,int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    heights[i][j] = 0;
                    q.push(make_pair(i,j));
                }
            }
        }
        
        while (!q.empty()) {
            auto curCel = q.front();
            q.pop();
            
            for (auto& direction: directions) {
                int newX = curCel.first + direction[0];
                int newY = curCel.second + direction[1];
                
                if (newX < 0 || newX >= m || newY < 0 || newY >= n)
                    continue;
                
                if (heights[newX][newY] != -1)
                    continue;
                
                heights[newX][newY] = heights[curCel.first][curCel.second] + 1;
                q.push(make_pair(newX, newY));
            }
        }
        
        return heights;
    }
};