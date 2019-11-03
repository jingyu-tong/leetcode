class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        vector<int> dp(n, 0);

        for(int i = 1; i < n; ++i) {
            dp[i] = max(0, dp[i - 1] + prices[i] - prices[i - 1]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};
