class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 1) return 0;
        int ans = 0;

        for(int i = 0; i < prices.size() - 1; ++i) {
            int profit = prices[i + 1] - prices[i];
            ans += profit > 0 ? profit : 0;
        }

        return ans;
    }
};
