//dfs tle
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans = INT_MAX;
        dfs(triangle, 0, 0, 0, ans);
        return ans;
    }
    void dfs(vector<vector<int>>& triangle, int loc, int level, int cur_ans, int& ans) {
        if(level == triangle.size()) {
            ans = min(ans, cur_ans);
            return;
        }
        dfs(triangle, loc, level + 1, cur_ans + triangle[level][loc], ans);
        dfs(triangle, loc + 1, level + 1, cur_ans + triangle[level][loc], ans);
    }

};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const int level = triangle.size();
        const int n = level;
        vector<vector<int>> dp(level, vector<int>(n));
        dp[0][0] = triangle[0][0];
        for(int i = 1; i < level; ++i) {
            for(int j = 0; j <= i; ++j) {
                if(j == 0) {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                } else if(j == i) {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
                }
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};
