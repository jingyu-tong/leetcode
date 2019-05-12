class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        int ans = 0;
        for(int i = 1; i < n; ++i) {
            int price = prices[i] - prices[i - 1]; 
            ans += price < 0 ? 0 : price;
        }
        return ans;
    }
};