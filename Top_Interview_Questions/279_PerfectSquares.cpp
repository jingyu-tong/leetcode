/*
**四平方定理。。。什么鬼
*/
class Solution {
public:
    int numSquares(int n) {
        while(n % 4 == 0) n = n / 4;
        if(n % 8 == 7) return 4;
        
        for(int i = 0; i * i < n; ++i) {
            int b = sqrt(n - i * i);
            if(i * i + b * b == n)
                return !!i + !!b;
        }
        return 3;
    }
};
/*
**dp	dp(n) = min(dp(n), dp(n - j * j) + 1)
*/
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; i + j * j <= n; ++j) {
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
            }
        }
        return dp.back();
    }
};