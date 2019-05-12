/*
**dp
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        vector<int> dp(prices.size());
        dp[0] = 0;
        for(int i = 1; i < dp.size(); ++i) {
            dp[i] = dp[i - 1] + prices[i] - prices[i - 1];
            if(dp[i] < 0) dp[i] = 0;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
/*
**进一步降维
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int dp = 0;
        int ans = 0;
        for(int i = 1; i < prices.size(); ++i) {
            dp = dp + prices[i] - prices[i - 1];
            if(dp > ans) ans = dp;
            if(dp < 0) dp = 0;
        }
        return ans;
    }
};