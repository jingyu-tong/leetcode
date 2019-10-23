class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;

        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == 0 && j == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                if(i == 0)
                    dp[i][j] = dp[i][j - 1] + grid[i][j - 1];
                else if(j == 0)
                    dp[i][j] = dp[i - 1][j] + grid[i - 1][j];
                else {
                    dp[i][j] = min(dp[i - 1][j] + grid[i - 1][j], dp[i][j - 1] + grid[i][j - 1]);
                }

            }
        }
        return dp[m - 1][n - 1] + grid[m - 1][n - 1];
    }
};
