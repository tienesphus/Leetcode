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
        
        queue<vector<int>> q;
        q.push({300,300});
        
        while (!q.empty()) {
            auto curCel = q.front();
            q.pop();
            //cout << "Current cel " << curCel[0] << " " << curCel[1] << '\n'; 
            if (curCel[0] == x && curCel[1] == y)
                return visited[curCel[0]][curCel[1]];
            
            for (auto& direction: directions) {
                int newX = curCel[0] + direction[0];
                int newY = curCel[1] + direction[1];
                
                if (newX < 0 || newX >= m || newY < 0 || newY >= n)
                    continue;
                
                if (visited[newX][newY] == -1) {
                    visited[newX][newY] = visited[curCel[0]][curCel[1]] + 1;
                    q.push({newX,newY});
                }
                
                //cout << "visited count:: " << newX << " " << newY << " " << visited[newX][newY] << '\n';
             }
        }
        
        return 0;
    }
};