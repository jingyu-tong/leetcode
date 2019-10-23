class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 1);
        for(int i = 1; i <= n; ++i) {
            if(i == 1) dp[i] = 1;
            else dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
