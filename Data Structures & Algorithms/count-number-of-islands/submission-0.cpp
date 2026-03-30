class Solution {
public:
    void bfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int row, int col, int n, int m) {
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        queue<pair<int,int>> q;
        q.push({row, col});
        visited[row][col] = true;
        while(!q.empty()) {
                auto item = q.front();
                q.pop();
            for(int i=0; i<4; i++) {
                int xRow = item.first + dx[i];
                int yCol = item.second + dy[i];
                // out of range check
                if(xRow < 0 || xRow >= n || yCol < 0 || yCol >=  m)
                    continue;
                    //non movable path
                if(visited[xRow][yCol] || grid[xRow][yCol] != '1')
                    continue;
                    //already visited
                visited[xRow][yCol] = true;
                q.push({xRow, yCol});
            }
        }
    }


    int numIslands(vector<vector<char>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       vector<vector<bool>> visited(n, vector<bool>(m, false)); 
       int ans = 0;
       for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!visited[i][j] && grid[i][j] == '1'){
                    bfs(grid, visited, i, j, n, m);
                    ans++;
                }
            }
       }
       return ans;
    }
};
