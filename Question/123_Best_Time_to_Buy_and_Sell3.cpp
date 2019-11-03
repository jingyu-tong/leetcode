class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;

        int n = prices.size();
        vector<vector<int>> local(n, vector<int>(3, 0));
        vector<vector<int>> global(n, vector<int>(3, 0));

        for(int i = 1; i < n; ++i) {
            int diff = prices[i] - prices[i - 1];
            for (int j = 1; j <= 2; ++j) {
                local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff);
                global[i][j] = max(local[i][j], global[i - 1][j]);
            }
        }
        return global[n - 1][2];
    }
};
