class Solution {
public:
    int minKnightMoves(int x, int y) {
        vector<vector<int>> directions = {{2,1}, {1,2}, {-1,2}, {1,-2}, {-1,-2}, {-2,1}, {2,-1}, {-2,-1}};
        x = x + 300;
        y = y + 300;
        vector<vector<int>> visited(601, vector<int>(601, -1));
        visited[300][300] = 0;
        int m = visited.size();
        int n = visited[0].size();
        
        queue<pair<int,int>> q;
        q.push({300,300});
        
        pair<int,int> curCel;
        int newX, newY;
        
        while (!q.empty()) {
            curCel = q.front();
            q.pop();

            if (curCel.first == x && curCel.second == y)
                return visited[curCel.first][curCel.second];
            
            for (auto& direction: directions) {
                newX = curCel.first + direction[0];
                newY = curCel.second + direction[1];
                
                if (newX < 0 || newX >= m || newY < 0 || newY >= n || visited[newX][newY] != -1)
                    continue;
                
                visited[newX][newY] = visited[curCel.first][curCel.second] + 1;
                q.push({newX,newY});
             }
        }
        return -1;
    }
};