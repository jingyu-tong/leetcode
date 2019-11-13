class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() <= 1) return 0;

        const int m = prices.size();

        //k超过prices的天数，直接贪心即可
        if(k >= m) return maxProfit(prices);

        //到i天之多j次交易，且最后一次在i天
        vector<vector<int>> local(m, vector<int>(k + 1, 0));
        //到i天至多j次，最优
        vector<vector<int>> global(m, vector<int>(k + 1, 0));
        for(int i = 1; i < m; ++i) {
            int diff = prices[i] - prices[i - 1];
            for(int j = 1; j <= k; ++j) {
                local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff);
                global[i][j] = max(local[i][j], global[i - 1][j]);
            }
        }
        return global[m - 1][k];
    }
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i - 1];
            ans += diff <= 0 ? 0 : diff;
        }
        return ans;
    }
};
