/*
**一维dp
*/
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1;
        //dp(n) = dp(n - 1) + dp(n - 2)
        vector dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i < n + 1; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
/*
**用两个数即可
*/
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1;
        //dp(n) = dp(n - 1) + dp(n - 2)
        vector dp(n + 1, 0);
        int dp0= 1;
        int dp1 = 1;
        for(int i = 2; i < n + 1; ++i) {
            dp0 = dp0 + dp1;
            swap(dp0, dp1);
        }
        return dp1;
    }
};