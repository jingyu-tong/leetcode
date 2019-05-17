/*
**dfs
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        const int m = grid.size();
        const int n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '0') continue;
                dfs(grid, i, j);
                ++ans;
            }
        }
        return ans;
    }
private:
    void dfs(vector<vector<char>>& grid, int x, int y) {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '0')
            return;
        grid[x][y] = '0';
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }
};
/*
**bfs
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        const int m = grid.size();
        const int n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '0') continue;
                queue<pair<int, int>> q;
                q.push({i, j});
                while(!q.empty()) {
                    auto node = q.front(); q.pop();
                    int x = node.first;
                    int y = node.second;
                    if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0') continue;
                    grid[x][y] = '0';
                    q.push({x + 1, y});
                    q.push({x - 1, y});
                    q.push({x, y + 1});
                    q.push({x, y - 1});
                }
                ++ans;
            }
        }
        return ans;
    }
};