class Solution {
public:
    int minKnightMoves(int x, int y) {
        if (x == 0 && y == 0)
            return 0;
        
        vector<pair<int,int>> directions = {{2,1}, {1,2}, {-1,2}, {1,-2}, {-1,-2}, {-2,1}, {2,-1}, {-2,-1}};
        x = x + 300;
        y = y + 300;
        vector<vector<int>> visited(601, vector<int>(601, -1));
        visited[300][300] = 0;
        int m = visited.size();
        int n = visited[0].size();
        
        queue<pair<int,int>> q;
        q.push({300,300});
        
        while (!q.empty()) {
            auto curCel = q.front();
            q.pop();
            
            for (auto& direction: directions) {
                int newX = curCel.first + direction.first;
                int newY = curCel.second + direction.second;
                
                if (newX < 0 || newX >= m || newY < 0 || newY >= n || visited[newX][newY] != -1)
                    continue;
                
                visited[newX][newY] = visited[curCel.first][curCel.second] + 1;
                
                if (newX == x && newY == y)
                    return visited[newX][newY];
                
                q.push({newX,newY});
             }
        }
        return -1;
    }
};