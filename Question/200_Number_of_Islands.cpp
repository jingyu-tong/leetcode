class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        
        int ans = 0;
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(used[i][j] || grid[i][j] == '0') continue;
                dfs(grid, used, i, j, m, n);
                ++ans;
            }
        }
        return ans;
    }
private:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& used, int x, int y, int m, int n) {
        if(x < 0 || x >= m || y < 0 || y >= n || used[x][y] || grid[x][y] == '0') return;
        
        used[x][y] = true;
        dfs(grid, used, x + 1, y, m, n);
        dfs(grid, used, x - 1, y, m, n);
        dfs(grid, used, x, y + 1, m, n);
        dfs(grid, used, x, y - 1, m, n);
    }
};