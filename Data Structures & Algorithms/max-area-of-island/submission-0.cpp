class Solution {
public:
    int bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col, int rows, int cols) {
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = true;
        int area = 0;
        while(!q.empty()) {
            auto dim = q.front();
            q.pop();
            area++;
            for(int i=0; i<4; i++) {
                int x = dim.first + dx[i];
                int y = dim.second + dy[i];
                if(x < 0 || x >=rows || y < 0 || y >= cols) continue;
                if(visited[x][y] || grid[x][y] == 0) continue;
                visited[x][y]  = true;
                q.push({x, y});
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(!visited[i][j] && grid[i][j] == 1){
                    auto currArea = bfs(grid, visited, i, j, rows, cols);
                   // cout << currArea << endl;
                    ans = max(ans, currArea);
                }
            }
        }       
        return ans; 
    }
};
