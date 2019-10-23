class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) return 0;
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();
        vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));

        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(obstacleGrid[i - 1][j - 1] == 1) {
                    continue;
                }
                if(i == 1 && j == 1)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m][n];
    }
};
