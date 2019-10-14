class Solution {
public:
    bool isMatch(string s, string p) {
        const int m = s.size();
        const int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        //dp(i, j) means s[0, i) and p[0, j) mathch state
        //p[j] != *, dp(i, j) = s[j - 1]  = p[j - 1] || p[j - 1] == .
        //p[j] == *, dp(i, j) = dp(i, j - 2) || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j])
        for(int i = 0; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(j > 1 && p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                } else {
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};
